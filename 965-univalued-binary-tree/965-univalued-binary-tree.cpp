class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root){
          return true;
        }
        int value=root->val;
        if(root->left){
            if(root->left->val!=value && isUnivalTree(root->left)){
                return false;
            }
        }
         if(root->right){
            if(root->right->val!=value && isUnivalTree(root->right)){
                return false;
            }
        }
       return isUnivalTree(root->left)&&isUnivalTree(root->right);
    }
};