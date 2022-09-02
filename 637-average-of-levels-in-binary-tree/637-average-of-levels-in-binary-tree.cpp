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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        if(!root) return res;
        queue<pair<TreeNode*,double>>q;
        q.push(make_pair(root,root->val));
        
        while(!q.empty()){
            int n=q.size();
            double total=0;
            double count=n;
            while(n--){
                auto temp=q.front();
                q.pop();
                TreeNode *start=temp.first;
                int val=temp.second;
                total+=val;
                if(start->left) q.push(make_pair(start->left,start->left->val));
                if(start->right) q.push(make_pair(start->right,start->right->val));
                
            }
            res.push_back(total/count);
        }
        return res;
    }
};