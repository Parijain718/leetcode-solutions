class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> prevGreater(n), nextGreater(n);
        vector<int> prevSmaller(n), nextSmaller(n);
        stack<int> st;
        while(!st.empty()) st.pop();
        for(int i = 0; i<n;i++){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = 0;i<n;i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long maxSum = 0;
        long long minSum = 0;
        for(int i = 0;i<n;i++){
            long long left = i - prevGreater[i];
            long long right = nextGreater[i] - i;
            maxSum += 1LL * nums[i] * left * right;
        }
        for(int i = 0;i<n;i++){
            long long left = i - prevSmaller[i];
            long long right = nextSmaller[i] - i;
            minSum += 1LL * nums[i] * left * right;
        }
        return maxSum - minSum;
    }
};