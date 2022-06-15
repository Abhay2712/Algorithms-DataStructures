// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int subfun(int i,int j,int arr[],vector<vector<int>>&dp){
        if(i==j) return 0;
        int mini=1e9,steps;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i;k<j;k++){
            steps=arr[i-1]*arr[k]*arr[j]+subfun(i,k,arr,dp)+subfun(k+1,j,arr,dp);
            mini=min(steps,mini);
        }
        return dp[i][j]=mini;
        
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int i=1,j=N-1;
        vector<vector<int>>dp(N,vector<int>(N,-1));
        return subfun(i,j,arr,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends