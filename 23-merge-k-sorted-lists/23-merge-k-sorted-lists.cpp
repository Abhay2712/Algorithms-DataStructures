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
    bool check(vector<ListNode*>&lists){
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL) return 1; 
        }
        return 0;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        ListNode* start=new ListNode;
        ListNode* temp=start;
        
        while(check(lists)){
            int pos=0,val=INT_MAX;
            for(int i=0;i<lists.size();i++){
                if(lists[i] && lists[i]->val<val){
                    val=lists[i]->val;
                    pos=i;
                }
            }
            temp->next=lists[pos];
            temp=temp->next;
            lists[pos]=lists[pos]->next;
        }
        return start->next;
    }
};