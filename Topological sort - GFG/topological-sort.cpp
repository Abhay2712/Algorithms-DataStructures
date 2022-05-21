// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	stack<int>st;
	//Function to return list containing vertices in Topological order. 
	void dfs(int i,int v,vector<int> adj[],vector<int>&visited){
	    if(visited[i]==-1){
	        visited[i]=0;
	        for(auto a:adj[i]){
	            dfs(a,v,adj,visited);
	        }
	        st.push(i);
	    }
	}
	
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // code here
	    vector<int>visited(v,-1);
	    for(int i=0;i<v;i++){
	        if(visited[i]==-1){
	            dfs(i,v,adj,visited);
	        }
	    }
	    vector<int>ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends