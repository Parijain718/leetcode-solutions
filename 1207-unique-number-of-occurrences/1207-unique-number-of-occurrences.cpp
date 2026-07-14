class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int num : arr){
            freq[num]++;
        }
        unordered_set<int> seen;
        for(auto it : freq){
            if(seen.count(it.second)){
                return false;
            }
            seen.insert(it.second);
        }
        return true;
    }
};