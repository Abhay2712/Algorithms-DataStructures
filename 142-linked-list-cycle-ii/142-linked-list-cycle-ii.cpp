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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode *slow=head->next;
        ListNode *fast=head->next->next;
        ListNode *entry=head;
        while(slow!=fast){
            if(!fast || !fast->next) return NULL;
            slow=slow->next;
            fast=fast->next->next;
        }
        while(entry!=slow){
            slow=slow->next;
            entry=entry->next;
        }
        return entry;
    }
};