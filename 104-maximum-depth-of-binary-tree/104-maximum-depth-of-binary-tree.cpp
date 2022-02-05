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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int max=1,count=1;
        traverse(root,count,max);
        return max;
        
    }
    
    void traverse(TreeNode *root,int &count,int &max){
        if(!root) return;
        
        if(root->left){
            count++;
            if(max<count) max=count;
            traverse(root->left,count,max);
            count--;
        }
        if(root->right){
            count++;
            if(max<count) max=count;
            traverse(root->right,count,max);
            count--;
        }
    }
    
    
};