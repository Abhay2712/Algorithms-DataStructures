// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
 public:
   int minJumps(int arr[], int n){
       // Your code here
       int maxjump=0;
       vector<int> m(n,0);
       m[0]=0;
       for(int i=0;i<n;i++){
           if(i>maxjump) return -1;
           for(int j=maxjump+1;j<=i+arr[i]&&j<n;j++){
               m[j]=m[i]+1;
           }
           maxjump=max(maxjump,i+arr[i]);
       }
       return m[n-1];
   }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends