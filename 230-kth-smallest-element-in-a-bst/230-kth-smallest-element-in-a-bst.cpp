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
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int res=0;
        subfun(root,k,count,res);
        return res;
    }
    
    void subfun(TreeNode *root,int k,int &count,int &res){
        if(!root) {
            return;
        }
        subfun(root->left,k,count,res);
        count++;
        if(count==k) {
            res=root->val;
        }
        
        subfun(root->right,k,count,res);
        
    }
};