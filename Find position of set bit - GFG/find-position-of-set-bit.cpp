// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        
        if(N & N-1 | N==0) return -1;
        
        // int pos=1;
        // while(N){
        //     if(N%2) return pos;
        //     N/=2;
        //     pos++;
        // }
        return (int)log2(N)+1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends