// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(int col,int n,vector<vector<int>> &ANS,vector<int> &temp,vector<int> &leftRow,vector<int> &uP,vector<int> &dW){
        if(col==n){
            ANS.push_back(temp);
            return;
        }

        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && uP[n-1+col-row]==0 && dW[col+row]==0){
                leftRow[row]=1;
                uP[n-1+col-row]=1;
                dW[col+row]=1;
                temp.push_back(row+1);
                solve(col+1,n,ANS,temp,leftRow,uP,dW);
                temp.pop_back();
                leftRow[row]=0;
                uP[n-1+col-row]=0;
                dW[col+row]=0;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ANS;
        vector<int> temp;
        vector<int> leftRow(n,0),uP(2 * n - 1,0),dW(2 * n - 1,0);
        solve(0,n,ANS,temp,leftRow,uP,dW);
        return ANS;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends