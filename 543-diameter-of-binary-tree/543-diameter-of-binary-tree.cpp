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
    int diameterOfBinaryTree(TreeNode* root) {
        int max=0;
        height(root,max);
        return max;
    }
    
    int height(TreeNode *root,int &maxo){
        if(!root) return 0;
        int lh=height(root->left,maxo);
        int rh=height(root->right,maxo);
        maxo=max(maxo,lh+rh);
        return 1+max(lh,rh);
    }
};