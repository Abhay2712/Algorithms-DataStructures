// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        priority_queue<int,vector<int>,greater<int>>q;
        int sum=0,val=0,temp;
        for(int i=0;i<N;i++){
            sum+=Arr[i];
            int j=0;
            temp=sum;
            while(j<=i){
                if(q.size()>=K){
                    if(temp>q.top()){
                        q.pop();
                        q.push(temp);
                    }
                }
                else q.push(temp);
                temp-=Arr[j];
                j++;
            }
        }
        return q.top();
    }
};

// { Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends