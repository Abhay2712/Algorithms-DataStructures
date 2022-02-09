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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>res;
        TreeNode* node=NULL;
        if(!root) return res;
        q.push(root);
        bool flag=1;
        while(!q.empty()){
            int size=q.size();
            vector<int>level(size);
            for(int i=0;i<size;i++){
                node=q.front();
                q.pop();
                int ind=(flag)?i:size-1-i;
                level[ind]=(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
            }
            flag=!flag;
            res.push_back(level);
        }
        return res;
        
    }
};