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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *a=head;
        ListNode *b=head->next;
        ListNode *prev=new ListNode;
        ListNode *temp=prev;
        while(b){
            if(b->next)
                a->next=b->next;
            else a->next=NULL;
            b->next=a;
            prev->next=b;
            prev=a;
            if(a->next) a=a->next; else a=NULL;
            if(a && a->next) b=a->next; else b=NULL;
        }
        
        return temp->next;
    }
};