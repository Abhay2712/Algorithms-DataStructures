class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>visited(n,0);
        dfs(0,rooms,visited);
        for(int i=0;i<n;i++){
            if(!visited[i]) return false;
        }
        return true;
    }
    
    void dfs(int i,vector<vector<int>>&rooms,vector<int>&visited){
        if(visited[i]) return;
        visited[i]=1;
        
        for(auto j:rooms[i]){
            dfs(j,rooms,visited);
        }
    }
};