class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> vp;
        for(int i = 0; i < n; i++)
            vp.push_back({nums2[i], nums1[i]});
        sort(vp.rbegin(), vp.rend());
        priority_queue<int,vector<int>,greater<int>> pq;
        long long sum = 0;
        long long ans = 0;
        for(auto &p : vp){
            sum += p.second;
            pq.push(p.second);
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k){
                ans = max(ans,sum*1LL*p.first);
            }
        }
        return ans;
    }
};