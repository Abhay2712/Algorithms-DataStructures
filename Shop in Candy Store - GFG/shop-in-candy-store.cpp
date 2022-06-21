// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int a[], int N, int K)
    {
        sort(a,a+N);
        int minSum=0,maxSum=0;
        int i=0,j=N-1;
        while(i<=j)
        {
            minSum+=a[i];
            i++;
            j-=K;
        }
        i=0,j=N-1;
        while(i<=j)
        {
            maxSum+=a[j];
            i+=K;
            j--;
        }
        return {minSum,maxSum};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends