// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int subfun(int i,int n,string &s,vector<int>&dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int mini=INT_MAX,cost;
        for(int j=i;j<n;j++){
            if(isPal(i,j,s)){
                cost=1+subfun(j+1,n,s,dp);
                mini=min(cost,mini);
            }
        }
        return dp[i]=mini;
    }

    bool isPal(int i,int j,string &s){
        while(i<j){
            if(s[i++]!=s[j--]) return 0;
        }
        return 1;
    }
    
    int palindromicPartition(string str)
    {
        vector<int>dp(str.size()+1,-1);
        return subfun(0,str.size(),str,dp)-1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends