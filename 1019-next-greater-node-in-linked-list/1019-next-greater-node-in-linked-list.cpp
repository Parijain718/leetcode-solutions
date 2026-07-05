class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }
        vector<int> ans(nums.size(),0);
        stack<int> st;
        for(int i = 0;i<nums.size();i++){
            while(!st.empty() && nums[i] > nums[st.top()]){
                ans[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};