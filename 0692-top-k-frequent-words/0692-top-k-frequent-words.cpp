class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(string word : words){
            mp[word]++;
        }
        vector<pair<string,int>> arr;
        for(auto &it :mp){
            arr.push_back({it.first,it.second});
        }
        sort(arr.begin(),arr.end(),[](auto &a,auto &b){
            if(a.second != b.second){
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        vector<string> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(arr[i].first);
        }
        return ans;
    }
};