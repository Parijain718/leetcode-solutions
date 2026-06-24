class Solution {
public:
    int lengthLongestPath(string input) {
        unordered_map<int,int> pathLen;
        pathLen[0] = 0;
        stringstream ss(input);
        string line;
        int ans = 0;
        while(getline(ss,line,'\n')){
            int depth = 0;
            while(depth < line.size() && line[depth] == '\t'){
                depth++;
            }
            string name = line.substr(depth);
            if(name.find('.') != string::npos){
                ans = max(ans,pathLen[depth] + (int)name.size());
            }
            else{
                pathLen[depth + 1] = pathLen[depth] + name.size() + 1;
            }
        }
        return ans;
    }
};