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
    bool isSymmetric(TreeNode* root) {
        TreeNode* root1=root->left;
        TreeNode* root2=root->right;
           
        return recursion(root1,root2);
    }
    
    bool recursion (TreeNode* root1,TreeNode* root2){
        if(!root1 || !root2) return root1==root2;
        
        if(root1->val != root2->val) return 0;
        
        return recursion(root1->left,root2->right) && recursion(root1->right,root2->left);
    }
};