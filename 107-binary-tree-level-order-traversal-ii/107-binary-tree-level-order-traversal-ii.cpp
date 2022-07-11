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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        vector<vector<int>>res;
        vector<int>vec;
        if(!root) return res;
        q.push(make_pair(root,root->val));
        
        
        while(!q.empty()){
            vec={};
            int n=q.size();
            while(n--){
                auto temp=q.front();
                q.pop();
                TreeNode *node=temp.first;
                int val=temp.second;
                vec.push_back(val);
                if(node->left) q.push(make_pair(node->left,node->left->val));
                if(node->right) q.push(make_pair(node->right,node->right->val));
                
            }
            res.push_back(vec);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};