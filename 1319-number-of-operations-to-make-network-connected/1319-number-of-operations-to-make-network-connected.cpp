class Solution {
public:
    void dfs(int i,vector<vector<int>>&adj,vector<int>&visited){
        visited[i]=1;    
        for(auto j:adj[i]){
            if(!visited[j]) dfs(j,adj,visited);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& conn) {
        int count=conn.size();
        if(count<n-1) return -1;
        
        vector<vector<int>>adj(n);
    
        for(auto i:conn){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>visited(n,0);
        
        int needed=0;
        for(int i=0;i<n;i++){
            if(!visited[i]) dfs(i,adj,visited),needed++;
        }
        
        return needed-1;
    }
};