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
    int diff=INT_MAX;
    TreeNode *prev=NULL;

    int getMinimumDifference(TreeNode* root) {
        if(root == NULL)
            return diff;
        
        getMinimumDifference(root->left);
        
        if(prev != NULL)
            diff = min(diff,abs(root->val - prev->val ));
        prev = root;
        
        getMinimumDifference(root->right);
        
        return diff;
    }
};
    