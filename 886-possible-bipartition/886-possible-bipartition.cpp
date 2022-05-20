class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto i:dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        if(check(adj,n)) return 1;
        else return 0;
    }
    
    bool check(vector<vector<int>>&adj,int n){
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!bfs(i,adj,color)){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool bfs(int i,vector<vector<int>>&adj,vector<int>&color){
        queue<int>q;
        q.push(i);
        color[i]=1;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            
            for(auto it:adj[a]){
                if(color[it]==-1){
                    color[it]=1-color[a];
                    q.push(it);
                }
                else if(color[it]==color[a]) return false;
            }
        }
        return true;
    }
};