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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *temp=head;
        ListNode *even=new ListNode(0);
        ListNode *e=even;
        ListNode *odd=new ListNode(0);
        ListNode *o=odd;
        int count=1;
        while(temp){
            if(count%2==0){
                even->next=temp;
                even=even->next;
            }
            else{
                odd->next=temp;
                odd=odd->next;
            }
            count++;
            temp=temp->next;
        }
        odd->next=e->next;
        even->next=NULL;
        return o->next; 
    }
};