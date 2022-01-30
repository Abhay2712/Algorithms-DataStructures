/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return 0;
        }
        ListNode *fast=head->next->next;
        ListNode *slow=head->next;
        while(fast && fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast ) return 1;
        }
        return 0;
    }
};