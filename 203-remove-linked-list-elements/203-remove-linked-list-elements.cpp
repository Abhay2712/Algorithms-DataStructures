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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p=head;
        ListNode *prev=new ListNode;
        ListNode *res=p;
        while(p){
            if(p->val==val && p==head){
                head=head->next;
            }
            else if(p->val==val){
                prev->next=p->next;
                p=p->next;
            }
            else{
                prev=p;
                p=p->next;
            }
        }
        return head;
        
    }
};