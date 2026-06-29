class Solution {
public:
    ListNode* merge(ListNode* a , ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(a && b){
            if(a->val < b->val){
                tail->next = a;
                a= a->next;
            }
            else{
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.empty())
            return nullptr;
        while(lists.size() > 1){
            vector<ListNode*> merged;
            for(int i = 0;i<lists.size();i+=2){
                ListNode* l1 = lists[i];
                ListNode* l2 = (i+1 < lists.size()) ? lists[i+1] : nullptr;
                merged.push_back(merge(l1,l2));
            }
            lists = merged;
        }
        return lists[0];
    }
};