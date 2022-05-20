// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int dp[501][2][201];
    vector<int> arr;
    
    int f(int i, bool buy, int k){
        if(i==arr.size()) return 0;
        
        if(dp[i][buy][k]!=-1) return dp[i][buy][k];
        
        int ans=f(i+1,buy,k);
        
        if(buy and k)
        ans=max(ans,-arr[i]+f(i+1,false,k));
        
        if(!buy)
        ans=max(ans,arr[i]+f(i+1,true,k-1));
        
        return dp[i][buy][k]=ans;
    }
    
    int maxProfit(int k, int n, int A[]) {
        memset(dp,-1,sizeof(dp));
        arr.resize(n);
        
        for(int i=0;i<n;i++)
        arr[i]=A[i];
        
        return f(0,true,k);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends