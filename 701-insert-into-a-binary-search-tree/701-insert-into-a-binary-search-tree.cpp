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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *ceil=new TreeNode(val);
        if(!root) return ceil;
        TreeNode *head=root;
        
        while(head){
            if(head->val<val){
                if(!head->right) {head->right=ceil;
                                 break;}
                head=head->right;
            }
            else {
                if(!head->left) {head->left=ceil;
                                 break;}
                
                else head=head->left;
            }
        }
        return root;
        
    }
};