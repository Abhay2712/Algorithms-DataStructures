// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
    int count=0;
    vector<vector<int>>v(grid.size());
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]=='1'){
                v[i].push_back(count);
                count++;
            }
            else v[i].push_back(-1);
        }
    }
    vector<int>adj[count];
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]!=-1){
                if(i+1<v.size() && v[i+1][j]!=-1)adj[v[i][j]].push_back(v[i+1][j]);
                if(i-1>=0 && v[i-1][j]!=-1)adj[v[i][j]].push_back(v[i-1][j]);
                if(j+1<v[i].size() && v[i][j+1]!=-1)adj[v[i][j]].push_back(v[i][j+1]);
                if(j-1>=0 && v[i][j-1]!=-1)adj[v[i][j]].push_back(v[i][j-1]);
                if(i+1<v.size() && j+1<v[i].size() && v[i+1][j+1]!=-1)adj[v[i][j]].push_back(v[i+1][j+1]);
                if(i+1<v.size() && j-1>=0 && v[i+1][j-1]!=-1)adj[v[i][j]].push_back(v[i+1][j-1]);
                if(i-1>=0 && j+1<v[i].size() && v[i-1][j+1]!=-1)adj[v[i][j]].push_back(v[i-1][j+1]);
                if(i-1>=0 && j-1>=0 && v[i-1][j-1]!=-1)adj[v[i][j]].push_back(v[i-1][j-1]);
            }
        }
    }
    int ans=0;
    vector<int>vis(count,0);
    for(int i=0;i<count;i++){
        if(vis[i]==0){
            ans++;
            queue<int>q;
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int node=q.front();
              //  cout<<node<<" ";
                q.pop();
                for(auto j:adj[node]){
                    if(vis[j]==0){
                        q.push(j);
                        vis[j]=1;
                    }
                }
            }
        }
    }
    return ans;
      }
};
// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends