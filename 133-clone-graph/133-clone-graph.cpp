class Solution {
public:
    unordered_map<Node* , Node*> mp; // declaring map, to check whwther we have a copy of node or not and also to store copy
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        
        Node* first = new Node(node -> val, {}); // make a copy of first node
        mp[node] = first;
        
        queue<Node*> q; 
        q.push(node); 
        
        while(q.empty() == false) 
        {
            Node* curr = q.front(); 
            q.pop();
            
            for(auto adj: curr -> neighbors) 
            {
                if(mp.find(adj) == mp.end()) 
                {
                    mp[adj] = new Node(adj -> val, {}); 
                    q.push(adj); 
                    
                }
                
                mp[curr] -> neighbors.push_back(mp[adj]); // in current node push adjcant node as neighbor
            }
        }
        
        return mp[node];
    }
};