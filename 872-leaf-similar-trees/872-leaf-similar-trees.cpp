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
    void helper(TreeNode *root,vector<int>&leafs){
        if(!root) return;
        if(!root->left && !root->right) leafs.push_back(root->val);
        
        helper(root->left,leafs);
        helper(root->right,leafs);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>t1;
        vector<int>t2;
        helper(root1,t1);
        helper(root2,t2);
        
        if(t1==t2) return true;
        return false;
        
    }
};