// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool subfun(int i,int sum,vector<int>&nums,vector<vector<int>>&dp){
        if(sum==0) return 1;
        if(i==0) return(nums[0]==sum);
        
        if(dp[i][sum]!=-1) return dp[i][sum];       //dp utilization
        
        bool notTake=subfun(i-1,sum,nums,dp);
        bool take=false;
        if(sum>=nums[i]) take=subfun(i-1,sum-nums[i],nums,dp);
        
        return dp[i][sum]=take||notTake;
        
    }

   int equalPartition(int N, int arr[])
   {
       vector<int>nums;
       for(int i=0;i<N;i++) nums.push_back(arr[i]);
       int sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size()-1;
        if(n==0) return 0;
        if(sum%2!=0) return false;
        sum/=2;
        
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));  //create a 2d dp for 0->n-1 elements and 0->k targets
        return subfun(n-1,sum,nums,dp);
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends