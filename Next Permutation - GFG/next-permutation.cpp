// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int idx=-1;
    // I) Start from the right most digit and find the first digit that is
    // smaller than the digit next to it.
       for(int i=N-1;i>0;i--)
       {
           if(arr[i-1]<arr[i])
           {
               idx=i;
               break;
               
               
               
           }
    // If no such digit is found, then all digits are in descending order
    // means there cannot be a greater number with same set of digits   
           
       }
       if(idx==-1)
       {
           reverse(arr.begin(),arr.end());
           return arr;
       }
      else
      {
          //Find the smallest digit on right side of (i-1)'th digit that is
    // greater than number[i-1]
          int prev=idx;
          int x=arr[idx-1];
          for(int i=idx;i<N;i++)
          {
             
              if(arr[i]>x && arr[i]<=arr[prev])
              prev=i; 
              
              
          }
           //Swap the above found smallest digit with number[i-1]
          swap(arr[prev],arr[idx-1]);
          //ll digits are linearly sorted in reverse order except one digit which was swapped
          //so we reverse the remaining
          reverse(arr.begin()+idx,arr.end());
          return arr;
          
          
          
      }
    
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends