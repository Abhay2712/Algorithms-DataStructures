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
    ListNode* middleNode(ListNode* head) {
        ListNode *p=head;
        ListNode *q=head;
        int r=0;
        while(q!=NULL){
            q=q->next;
            r++;
        }
        r=r/2;
        while(r>0){
            p=p->next;
            r--;
        }
        return p;
    }
};