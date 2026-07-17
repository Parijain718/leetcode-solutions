class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        vector<long long> gcdCnt(mx + 1, 0);

        
        for (int i = mx; i >= 1; i--) {

            long long cnt = 0;

            for (int j = i; j <= mx; j += i)
                cnt += freq[j];

            gcdCnt[i] = cnt * (cnt - 1) / 2;

            for (int j = i * 2; j <= mx; j += i)
                gcdCnt[i] -= gcdCnt[j];
        }

        
        vector<long long> pref(mx + 1, 0);
        for (int i = 1; i <= mx; i++)
            pref[i] = pref[i - 1] + gcdCnt[i];

        vector<int> ans;

        for (long long q : queries) {
            int g = lower_bound(pref.begin(), pref.end(), q + 1) - pref.begin();
            ans.push_back(g);
        }

        return ans;
    }
};