class Solution {
public:
    static const int MOD = 1e9 + 7;

    int dp[205][201][201];
    bool vis[205][201][201];

    int solve(int idx, int g1, int g2, vector<int>& nums) {
        if (idx == nums.size()) {
            return (g1 != 0 && g1 == g2);
        }

        if (vis[idx][g1][g2])
            return dp[idx][g1][g2];

        vis[idx][g1][g2] = true;

        long long ans = 0;

        // Skip current element
        ans += solve(idx + 1, g1, g2, nums);

        // Put in first subsequence
        int ng1 = (g1 == 0) ? nums[idx] : gcd(g1, nums[idx]);
        ans += solve(idx + 1, ng1, g2, nums);

        // Put in second subsequence
        int ng2 = (g2 == 0) ? nums[idx] : gcd(g2, nums[idx]);
        ans += solve(idx + 1, g1, ng2, nums);

        return dp[idx][g1][g2] = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(vis, 0, sizeof(vis));
        return solve(0, 0, 0, nums);
    }
};