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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=1;
        ListNode *temp=head;
        while(temp->next){
            temp=temp->next;
            n++;
        }
        int i=n/k;
        return reverse(head,k,i);
    }
    
    ListNode* reverse(ListNode* head, int k,int &i) { //recursive subfunction
    if (!head)  //base case
        return NULL;
    ListNode* current = head;
    ListNode* next = NULL;
    ListNode* prev = NULL;
    int count = 0;

    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    i-=1;
    /* next is now a pointer to (k+1)th node
    Recursively call for the list starting from current.
    And make rest of the list as next of first node */
    if (next != NULL && i){
        head->next = reverse(next, k,i);
    }
    else head->next=next;
    /* prev is new head of the input list */
    return prev;
}
};