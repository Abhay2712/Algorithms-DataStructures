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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //If right == left then no need to reverse
		if(!head or left == right)
            return head;
		
		//inserting dummy node in front
        ListNode *dummy = new ListNode(0);
        dummy->next =head;
		
		// L is pointer to the left node to reverse ans LEFT_PTR is pointer left of L (just before L)
        ListNode *L ,*LEFT_PTR=dummy;
        for(int i=0;i<left-1;i++)
            LEFT_PTR = LEFT_PTR->next;
		
        L = LEFT_PTR->next;
		 
		 //JUST REVERSE LOGIC HERE
        for(int i=0;i<right-left;i++){
            ListNode *tmp  = LEFT_PTR->next;
            LEFT_PTR->next = L->next;
            L->next  =  L->next->next;
            LEFT_PTR->next->next = tmp;
        }
        return dummy->next;
    }
};