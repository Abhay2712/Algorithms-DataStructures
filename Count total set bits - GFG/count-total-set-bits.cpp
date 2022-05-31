// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
        {
            if(n<=0) return 0;
            int x=0;
            int a=1;
            while((a<<1)<=n){
                a<<=1;
                x++;
            }
            return (pow(2,x-1)*x+(n-pow(2,x)+1)+countSetBits(n-pow(2,x)));
        }
         
        // A utility function to count set bits
        // in a number x
    int countSetBitsUtil(int x)
        {
            if (x <= 0)
                return 0;
            return (x % 2 == 0 ? 0 : 1) + countSetBitsUtil(x / 2);
        }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends