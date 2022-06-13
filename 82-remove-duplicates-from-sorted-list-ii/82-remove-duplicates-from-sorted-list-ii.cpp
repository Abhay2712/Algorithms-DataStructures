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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode *prev=NULL, *curr=head, *next=curr->next;
        while(next)
        {
            if(curr->val == next->val)
            {
                while(next && next->val == curr->val)
                    next=next->next;
                if(!prev) // This condition means element at the head is repeating. So, head pointer needs to be shifted.
                    head=next;
                else
                    prev->next = next;
            }
            else
            {
                prev=curr;
            }
            
            curr=next;
            if(next)
                next=curr->next;
        }
        return head;
    }
};