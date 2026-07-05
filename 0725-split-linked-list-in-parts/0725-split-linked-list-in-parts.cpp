class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* curr = head;
        while(curr){
            len++;
            curr = curr->next;
        }
        int partSize = len / k;
        int extra = len % k;
        vector<ListNode*> ans(k);
        curr = head;
        for(int i = 0;i<k;i++){
            if(!curr){
                ans[i] = nullptr;
                continue;
            }
            ans[i] = curr;
            int currentSize = partSize;
            if(extra > 0){
                currentSize++;
                extra--;
            }
            for(int j = 1;j<currentSize;j++)
                curr = curr->next;
            ListNode* next = curr->next;
            curr->next = nullptr;
            curr = next;
        }
        return ans;
    }
};