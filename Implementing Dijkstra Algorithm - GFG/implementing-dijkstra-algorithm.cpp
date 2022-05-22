// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>vis(n+1,1e9);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
        q.push({0,S});
        vis[S]=0;
        
        while(!q.empty()){
            vector<int>temp=q.top();
            q.pop();
            int a=temp[0];
            int b=temp[1];
            if(a>vis[b]) continue;
            for(auto i:adj[b]){
                if(vis[i[0]]>vis[b]+i[1]){
                    vis[i[0]]=i[1]+vis[b];
                    q.push({vis[i[0]],i[0]});
                }
            }
        }
        return vis;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends