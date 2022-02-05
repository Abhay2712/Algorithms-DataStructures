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
    bool isBalanced(TreeNode* root) {
        return dfsHeight (root) != -1;
    }
    int dfsHeight (TreeNode *root) {
        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight (root -> left);
        if (leftHeight == -1) return -1;
        int rightHeight = dfsHeight (root -> right);
        if (rightHeight == -1) return -1;
        
        if (abs(leftHeight - rightHeight) > 1)  return -1;
        return max (leftHeight, rightHeight) + 1;
    }
};
//     bool isBalanced(TreeNode* root) {
//         return height(root)!=-1;
//     }
    
//     int height(TreeNode *root){
//         if(!root) return 0;
        
//         int lh=height(root->left);
//         if(lh==-1) return -1;
//         int rh=height(root->right);
//         if(rh==-1) return -1;
        
//         if(abs(lh-rh>1)) return -1;
//         return max(lh,rh) + 1;
//     }
// };