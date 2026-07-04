class Solution {
public:
    int maximumGap(vector<int>& nums) {

        int n = nums.size();

        if (n < 2)
            return 0;

        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());

        if (minNum == maxNum)
            return 0;

        int bucketSize = max(1, (maxNum - minNum) / (n - 1));
        int bucketCount = (maxNum - minNum) / bucketSize + 1;

        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);
        vector<bool> used(bucketCount, false);

        for (int num : nums) {

            int idx = (num - minNum) / bucketSize;

            bucketMin[idx] = min(bucketMin[idx], num);
            bucketMax[idx] = max(bucketMax[idx], num);
            used[idx] = true;
        }

        int ans = 0;
        int prev = minNum;

        for (int i = 0; i < bucketCount; i++) {

            if (!used[i])
                continue;

            ans = max(ans, bucketMin[i] - prev);

            prev = bucketMax[i];
        }

        return ans;
    }
};