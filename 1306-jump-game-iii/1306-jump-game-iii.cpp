class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<vector<int>>adj(n,vector<int>());
        
        for(int i=0;i<n;i++){
            if(i-arr[i]>=0) adj[i].push_back(i-arr[i]);
            if(i+arr[i]<n) adj[i].push_back(i+arr[i]);
        }

        queue<int>q;
        q.push(start);
        vector<int>visited(n,0);
        
        while(!q.empty()){
            int len=q.size();
            while(len--){
                int top=q.front();
                visited[top]=1;
                q.pop();
                for(auto i:adj[top]){
                    if(arr[i]==0) return true;
                    if(!visited[i]) q.push(i);
                }
            }
        }
        return false;
    }
};