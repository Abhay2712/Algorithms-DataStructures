// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int nums[])
    {
       // your code here
       vector<int>dp;
        dp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>dp.back()) dp.push_back(nums[i]);
            else{
                int ind=lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
                dp[ind]=nums[i];
            }
        }
        return dp.size();
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends