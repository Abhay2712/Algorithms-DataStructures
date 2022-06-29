class Solution {
public:
    bool subfun(int i,vector<vector<int>>&adj,vector<int>&visited,int dest){
        if(i==dest) return true;
        if(visited[i]) return false;
        visited[i]=1;
        for(auto j:adj[i]){
            if(subfun(j,adj,visited,dest)) return true;
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        vector<int>visited(n,0);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        return subfun(source,adj,visited,destination);
    }
};