class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mask;

        for (auto &r : reservedSeats) {
            mask[r[0]] |= (1 << (r[1] - 1));
        }

        int ans = (n - mask.size()) * 2;

        int leftMask  = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4); // 2-5
        int midMask   = (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6); // 4-7
        int rightMask = (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8); // 6-9

        for (auto &[row, m] : mask) {
            bool left = !(m & leftMask);
            bool mid = !(m & midMask);
            bool right = !(m & rightMask);

            if (left && right)
                ans += 2;
            else if (left || mid || right)
                ans += 1;
        }

        return ans;
    }
};