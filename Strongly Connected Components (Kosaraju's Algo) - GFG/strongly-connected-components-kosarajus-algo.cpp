// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<int> adj[])
    {
        //code here
        stack<int>st;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs(i,st,vis,adj);
        }
        
        vector<int>transpose[n];
        for(int i=0;i<n;i++){
            vis[i]=0;
            for(auto it:adj[i])
                transpose[it].push_back(i);
        }
        int count=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
               count++;
               rdfs(node,vis,transpose);
            }
        }
        
        return count;
    }
    
    void dfs(int i,stack<int>&st,vector<int>&vis,vector<int>adj[]){
        vis[i]=1;
        for(auto it: adj[i]){
            if(!vis[it]) dfs(it,st,vis,adj);
        }
        st.push(i);
    }
    
    void rdfs(int i,vector<int>&vis,vector<int>transpose[]){
        vis[i]=1;
        for(auto it:transpose[i]){
            if(!vis[it]){
                rdfs(it,vis,transpose);
            }
        }
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends