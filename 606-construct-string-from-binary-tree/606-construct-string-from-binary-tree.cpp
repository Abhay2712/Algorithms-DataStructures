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
    string str="";
    void dfs(TreeNode *root){
        if(!root) return;
        str+=to_string(root->val);
        
        if(root->left || root->right)
        {str+='(';
        if(root->left) {dfs(root->left);}
        str+=')';
        }
        if(root->right) {
            str+='(';
            dfs(root->right);
            str+=')';
        }
        
    }
    
    string tree2str(TreeNode* root) {
        dfs(root);
        return str;
    }
};