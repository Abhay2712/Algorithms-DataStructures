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
        vector<int>level;
        TreeNode* node=NULL;
        if(!root) return res;
        q.push(root);
        int count=0;
        while(!q.empty()){
            count++;
            int size=q.size();
            level={};
            for(int i=0;i<size;i++){
                node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                level.push_back(node->val);
            }
            if(count%2==0) reverse(level.begin(),level.end());
            res.push_back(level);
        }
        return res;
        
    }
};