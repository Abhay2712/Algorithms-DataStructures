/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool a=1;
        check(p,q,a);
        if(a) return 1;
        else return 0;
        
    }
    
    void check(TreeNode*p,TreeNode*q,bool &a){
        
        if(!p || !q) {
            if(p!=q) a=0;
            return;
            }
        if(p->val!=q->val) a=0;
        if(a)check(p->left,q->left,a);
        if(a)check(p->right,q->right,a); 
        return;
        
    }
};