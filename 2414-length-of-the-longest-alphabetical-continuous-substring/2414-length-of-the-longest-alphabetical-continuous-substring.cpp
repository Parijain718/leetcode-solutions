class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 1;
        int curr = 1;
        for(int i = 1;i<s.size();i++){
            if(s[i] == s[i-1]+1){
                curr++;
            }
            else{
                curr = 1;
            }
            ans = max(ans,curr);
        }
        return ans;
    }
};