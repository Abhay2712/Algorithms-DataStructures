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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL ||k==0) return head; 
        ListNode *temp=head;
        ListNode *res=head;
        int n=0,i=0;       
        while(temp){
            temp=temp->next;
            n++;
        }
        k=k%n;
        if(k==0) return head;
        while(i++<n-k){
            res=res->next;
            // cout<<i;
        }
        temp=res;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=head;
        temp=head;
        i=0;
        while(i++<n-k-1){
            temp=temp->next;
            cout<<i;
        }
        temp->next=NULL;
        return res;
        
    }
};