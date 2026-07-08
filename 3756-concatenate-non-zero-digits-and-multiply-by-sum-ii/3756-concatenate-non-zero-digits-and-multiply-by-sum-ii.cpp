class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        int n = s.size();

        vector<int> digits;
        vector<int> pos;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int m = digits.size();

        vector<long long> preNum(m + 1, 0);
        vector<long long> preSum(m + 1, 0);
        vector<long long> pow10(m + 1, 1);

        for (int i = 0; i < m; i++) {
            preNum[i + 1] = (preNum[i] * 10 + digits[i]) % MOD;
            preSum[i + 1] = preSum[i] + digits[i];
        }

        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // nextIdx[i] = first compressed index whose original position >= i
        vector<int> nextIdx(n, -1);
        int p = 0;
        for (int i = 0; i < n; i++) {
            while (p < m && pos[p] < i)
                p++;
            if (p < m)
                nextIdx[i] = p;
        }

        // prevIdx[i] = last compressed index whose original position <= i
        vector<int> prevIdx(n, -1);
        p = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (p >= 0 && pos[p] > i)
                p--;
            if (p >= 0)
                prevIdx[i] = p;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = nextIdx[q[0]];
            int r = prevIdx[q[1]];

            if (l == -1 || r == -1 || l > r) {
                ans.push_back(0);
                continue;
            }

            int len = r - l + 1;

            long long num =
                (preNum[r + 1] -
                 (preNum[l] * pow10[len]) % MOD +
                 MOD) % MOD;

            long long sum = preSum[r + 1] - preSum[l];

            ans.push_back((num * sum) % MOD);
        }

        return ans;
    }
};