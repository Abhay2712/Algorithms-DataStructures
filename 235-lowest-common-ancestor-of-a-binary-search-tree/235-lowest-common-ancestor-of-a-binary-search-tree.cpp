/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            int curr=root->val;
            if(curr<p->val && curr<q->val) root=root->right;
            else if(curr>p->val && curr>q->val) root=root->left;
            else break;
        }
        // if(!root) return NULL;
        // int curr=root->val;
        // if(curr<p->val && curr<q->val){
        //     return lowestCommonAncestor(root->right,p,q);
        // }
        // else if(curr>p->val && curr>q->val){
        //     return lowestCommonAncestor(root->left,p,q);
        // }
        // else return root;
        return root;
    }
};