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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>s;
        return bfs(root,k,s);
    }
    
    bool bfs(TreeNode*root,int k,unordered_set<int>&s){
        if(!root) return 0;
        if(s.find(k-root->val)!=s.end()) return 1;
        s.insert(root->val);
        return bfs(root->left,k,s) || bfs(root->right,k,s);
    }
};