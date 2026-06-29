class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for(string p : patterns){
            int len = p.size();
            for(int i = 0; i + len <= word.size();i++){
                if(word.substr(i,len) == p){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};