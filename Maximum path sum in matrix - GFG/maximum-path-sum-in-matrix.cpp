// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>>matrix)
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            int ans=getMax(n-1,i,matrix,dp);
            maxi=max(maxi,ans);
        }
        return maxi;
    }
    
    int getMax(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        
        if(j<0 || j>=matrix.size()) return -1e9;
        if(i==0) return matrix[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        int up=getMax(i-1,j,matrix,dp);
        int ld=getMax(i-1,j-1,matrix,dp);
        int rd=getMax(i-1,j+1,matrix,dp);
        
        return dp[i][j]=matrix[i][j]+max(up,max(ld,rd));
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends