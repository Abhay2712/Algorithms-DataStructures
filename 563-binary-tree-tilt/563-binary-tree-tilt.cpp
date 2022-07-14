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

    int result = 0;
    int depthfirstsearch(TreeNode *root) {
        int left = (root->left ? depthfirstsearch(root->left) : 0);
        int right = (root->right ? depthfirstsearch(root->right) : 0);
        // Finding the current tilt( |left-right| )
		result += abs(left - right);
		// returning the total sum
        return left + right + root->val;
    }
    int findTilt(TreeNode* root) {
        if (root) depthfirstsearch(root);
        return result;
    }
};