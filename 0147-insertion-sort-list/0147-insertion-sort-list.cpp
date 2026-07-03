class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode* curr = head;
        while(curr){
            ListNode* next = curr->next;
            ListNode* prev = &dummy;
            while(prev->next && prev->next->val < curr->val){
                prev = prev->next;
            }
            curr->next = prev->next;
            prev->next = curr;
            curr = next;
        }
        return dummy.next;
    }
};