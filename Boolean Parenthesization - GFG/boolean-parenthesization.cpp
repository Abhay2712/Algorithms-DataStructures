// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution{
public:
    int subfun(int i,int j,int isTrue,string &S,vector<vector<vector<int>>>&dp){
        if(i>j) return 0;
        if(i==j) {
            if(isTrue)
                return S[i]=='T';
            else 
                return S[i]=='F';
        }
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        int ways=0;
        
        for(int k=i+1;k<=j-1;k=k+2){
            int lT=subfun(i,k-1,1,S,dp);
            int lF=subfun(i,k-1,0,S,dp);
            int rT=subfun(k+1,j,1,S,dp);
            int rF=subfun(k+1,j,0,S,dp);
            
            if(S[k]=='&'){
                if(isTrue) ways+=lT*rT;
                else ways+=lT*rF+lF*rT+rF*lF;
            }
            else if(S[k]=='|'){
                if(isTrue) ways+=lT*rT+lT*rF+lF*rT;
                else ways+=rF*lF;
            }
            else{
                if(isTrue) ways+=lT*rF+lF*rT;
                else ways+=lT*rT+rF*lF;
            }
        }
        return dp[i][j][isTrue]=(ways%1003);
    }
    
    int countWays(int N, string S){
        // code here
        vector<vector<vector<int>>>dp(S.size()+1,vector<vector<int>>(S.size()+1,vector<int>(2,-1)));
        int res=subfun(0,S.size()-1,1,S,dp);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends