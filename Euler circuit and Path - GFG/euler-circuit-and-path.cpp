// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void DFS(int node, vector<bool> &visited, vector<int>adj[]) {
        
        visited[node] = true;
        for(auto i: adj[node]) {
            if(!visited[i]) {
                DFS(i,visited,adj);
            }
        }
    }
    
    bool isConnected(int V, vector<int>adj[]) {
        
        vector<bool> visited(V, false);
        
        int i = 0;
        for(; i < V; i++) {
            if(adj[i].size() != 0) {
                break;
            }
        }
        
        if(i == V) {
            return true;
        }
        
        DFS(i, visited, adj);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i] and adj[i].size() != 0) {
                return false;
            }
        }
        
        return true;
        
    }

	int isEularCircuit(int V, vector<int>adj[]) {
	    
	    
	    if(isConnected(V, adj) == false) {
	        return 0;
	    }
	    
	    // Check for odd degree
	    int odd = 0;
	    
	    for(int i = 0; i < V; i++) {
	        if(adj[i].size() & 1) {
	            odd++;
	        }
	    }
	    
	    if(odd == 0) {
	        return 2;
	    }
	    
	    if(odd == 2) {
	        return 1;
	    }
	    
	    if(odd > 2) {
	        return 0;
	    }
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEularCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}  // } Driver Code Ends