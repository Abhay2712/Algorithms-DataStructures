class Solution {
public:
    bool solve(int i,int j,vector<vector<int>>&adj,vector<int>&color){
        for(auto k:adj[i]){
            if(color[k]==j) return false;
        }
        return true;
    }
    
    bool subfun(int i,int n,vector<vector<int>>& adj,vector<int>&color){
        if(i==n) return true;
        
        for(int j=1;j<=4;j++){
            if(solve(i,j,adj,color)){
                color[i]=j;
                if(subfun(i+1,n,adj,color)) return true;
                // if(i!=n-2) color[i]=0;
            }
        }
        return false;
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>adj(n);
        for(auto i:paths){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        vector<int>color(n,0);
        subfun(0,n,adj,color);
        return color;
    }
};