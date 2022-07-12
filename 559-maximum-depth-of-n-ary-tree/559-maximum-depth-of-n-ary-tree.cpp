/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int height=0;
        
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            height++;
            while(n--){
                Node *temp=q.front();
                q.pop();
                for(auto i:temp->children) q.push(i);
            }
        }
        return height;
    }
};