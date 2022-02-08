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
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        maxpath(root,sum);
        return sum;
    }
    
    int maxpath(TreeNode* root,int &sum){
        if(!root){
            return 0;
        }
        int ls=max(0,maxpath(root->left,sum));
        int rs=max(0,maxpath(root->right,sum));
        sum=max(sum,ls+rs+root->val);
        return (root->val)+max(ls,rs);
    }
};