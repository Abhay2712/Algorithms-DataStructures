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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh=leftheight(root);
        int rh=rightheight(root);
        // cout<<lh<<" "<<rh<<"\n";
        if (lh==rh) return(1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    
    int rightheight(TreeNode*root){
        int height=1;
        while(root->right){
            root=root->right;
            height++;
        }
        return height;
    }
    
    int leftheight(TreeNode* root) {
        int height=1;
        while(root->left){
            root=root->left;
            height++;
        }
        return height;
    }
};