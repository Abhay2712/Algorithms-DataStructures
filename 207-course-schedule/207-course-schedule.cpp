class Solution {
public:
    bool cdfs(int i,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&extra){
        visited[i]=1;
        extra[i]=1;
        for(auto it:adj[i]){
            if(!visited[it])
            {
                if(cdfs(it,adj,visited,extra)) return 1;
            }
            else if(extra[it]) return 1;
        }
        extra[i]=0;
        return 0;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n,vector<int>());
        vector<bool>visited(n,0);
        vector<bool>extra(n,0);
        for(auto i:pre){
            adj[i[0]].push_back(i[1]);
        }
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(cdfs(i,adj,visited,extra)) return 0;        
            }
        }
        return 1;
    }
};