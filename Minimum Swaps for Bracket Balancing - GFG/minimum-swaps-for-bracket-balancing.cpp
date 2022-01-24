// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string &S){
        // code here 
        int count=0,sum=0;
        for(int i=0;i<S.size();i++){
            if(S[i]==']'){
                count++;    //keep adding until you find opening bracket
            }
            else {
                if(count>0){
                sum+=count; //as we find the opening bracket we will do the count number
                }           // of shifts to make it reach the first closing bracket(2 swaps)
                count--;    //]][[  ][][    []][
            }               //now we found the 2nd opening bracket and count=1 so we did 1 swap
        }                   //[][]
        return sum;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends