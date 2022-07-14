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
    int ans = INT_MAX;
    int parent = INT_MAX;
    void inorder(TreeNode*root) {    
        if(root == NULL) return;
        inorder(root->left);
        ans = min(ans, abs(parent-root->val));
        parent = root->val;
        inorder(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
};