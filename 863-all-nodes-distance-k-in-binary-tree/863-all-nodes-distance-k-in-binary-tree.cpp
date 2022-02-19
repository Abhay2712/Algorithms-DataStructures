/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode *root,unordered_map<TreeNode*,TreeNode*>&parent,TreeNode *target){
        queue<TreeNode*>q;
        q.push(root);       //graph question done using trees
        while(!q.empty()){
            TreeNode *curr=q.front();
            q.pop();
            if(curr->left){
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>res;
        unordered_map<TreeNode*,TreeNode*>parent;
        markParents(root,parent,target);
        unordered_map<TreeNode*,bool>visited;
        
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            if(level++==k) break;
            for(int i=0;i<size;i++){
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){ //travel left
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                if(curr->right && !visited[curr->right]){ //travel right
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                if(parent[curr] && !visited[parent[curr]]){ //travel up
                    q.push(parent[curr]);
                    visited[parent[curr]]=true;
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};