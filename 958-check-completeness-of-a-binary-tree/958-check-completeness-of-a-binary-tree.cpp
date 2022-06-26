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
    int countNodes(TreeNode* root)
    {
        if (root == NULL)
            return (0);
        return (1 + countNodes(root->left) + countNodes(root->right));
    }
    
    bool isComplete ( TreeNode* root, int index, int number_nodes)
    {
        if (root == NULL)
            return (true);

        if (index >= number_nodes)
            return (false);

        return (isComplete(root->left, 2*index + 1, number_nodes) &&
                isComplete(root->right, 2*index + 2, number_nodes));
    }
    
    bool isCompleteTree(TreeNode* root) {
        int num=countNodes(root);
        return isComplete(root,0,num);
    }
};