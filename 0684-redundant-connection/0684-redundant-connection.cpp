class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    bool unite(int a,int b){
        int rootA = find(a);
        int rootB = find(b);
        if(rootA == rootB) 
            return false;
        parent[rootB] = rootA;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            if(!unite(u,v)){
                return {u,v};
            }
        }
        return {};
    }
};