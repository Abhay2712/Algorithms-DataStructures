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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
        {
            return false;
        }
        targetSum -= root->val;
        if(targetSum==0 && root->left == NULL && root->right == NULL)
        {
            return true;
        }
        return(hasPathSum(root->left, targetSum)|| hasPathSum(root->right, targetSum));
    }
};


//BFS solution
// class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int target) {
//         queue<pair<TreeNode*,int>>q;
//         if(!root) return false;
//         q.push(make_pair(root,target-root->val));
//         while(!q.empty()){
//             int n=q.size();
//             while(n--){
//                 auto start=q.front();
//                 TreeNode *temp=start.first;
//                 int val=start.second;
//                 q.pop();
//                 if(!temp->left && !temp->right && val==0) return true;
                
//                 if(temp->left) q.push(make_pair(temp->left,val-temp->left->val));
//                 if(temp->right) q.push(make_pair(temp->right,val-temp->right->val));
                
//             }
//         }
//         return false;
        
        
//     }
// };