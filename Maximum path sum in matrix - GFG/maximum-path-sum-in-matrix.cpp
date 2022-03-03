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
//tabulation approach
// int getMaxPathSum(vector<vector<int> > &matrix){
    
//     int n = matrix.size();
//     int m = matrix[0].size();
    
//     vector<vector<int>> dp(n,vector<int>(m,0));
    
//     // Initializing first row - base condition
//     for(int j=0; j<m; j++){
//         dp[0][j] = matrix[0][j];
//     }
    
//     for(int i=1; i<n; i++){
//         for(int j=0;j<m;j++){
            
//             int up = matrix[i][j] + dp[i-1][j];
            
//             int leftDiagonal= matrix[i][j];
//             if(j-1>=0) leftDiagonal += dp[i-1][j-1];
//             else leftDiagonal += -1e9;
            
//             int rightDiagonal = matrix[i][j];
//             if(j+1<m) rightDiagonal += dp[i-1][j+1];
//             else rightDiagonal += -1e9;
            
//             dp[i][j] = max(up, max(leftDiagonal,rightDiagonal));
            
//         }
//     }

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