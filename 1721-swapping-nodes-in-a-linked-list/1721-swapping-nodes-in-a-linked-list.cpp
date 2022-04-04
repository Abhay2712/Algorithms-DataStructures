/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *temp1=head,*temp2=head;
        int start=k-1;
        while(0<start--){
            temp1=temp1->next;
        }
        ListNode *fast=temp1;
        while(fast->next){
            fast=fast->next;
            temp2=temp2->next;
        }
        int value=temp2->val;
        temp2->val=temp1->val;
        temp1->val=value;
        
        return head;
        
        
    }
};