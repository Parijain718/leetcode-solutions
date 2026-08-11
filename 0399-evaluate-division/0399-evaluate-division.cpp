class Solution {
public:
    bool dfs(string curr, string target, unordered_map<string,vector<pair<string,double>>>& graph, unordered_set<string>& visited, double product, double& ans){
        if(curr == target){
            ans = product;
            return true;
        }
        visited.insert(curr);
        for(auto &[next,weight] : graph[curr]){
            if(visited.count(next))
                continue;
            if(dfs(next,target,graph,visited,product*weight,ans)){
                return true;
            }
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for(int i = 0; i < equations.size(); i++){
            string a = equations[i][0];
            string b = equations[i][1];
            double value = values[i];
            graph[a].push_back({b,value});
            graph[b].push_back({a,1.0/value});
        }
        vector<double> result;
        for(auto &query : queries){
            string start = query[0];
            string target = query[1];
            if(!graph.count(start) || !graph.count(target)){
                result.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            double ans = -1.0;
            dfs(start,target,graph,visited,1.0,ans);
            result.push_back(ans);
        }
        return result;
    }
};