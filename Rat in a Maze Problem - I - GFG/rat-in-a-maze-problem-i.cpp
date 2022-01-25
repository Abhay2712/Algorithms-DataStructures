// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>res;
        string s="";
        if(m[0][0]==0 || m[n-1][n-1]==0){
            return {"-1"};
        }
        subfun(m,n,0,0,s,res);
        return res;
    }
    void subfun(vector<vector<int>>&m,int n,int i,int j,string &s,vector<string>&res){
        if(i==j && i==n-1){
            res.push_back(s);
            return;
        }
        if(i+1<n && m[i+1][j]==1){
            s+="D";
            m[i][j]=0;
            subfun(m,n,i+1,j,s,res);
            s.resize(s.size()-1);
            m[i][j]=1;
        }
        if(j>0 && m[i][j-1]==1){
            s+="L";
            m[i][j]=0;
            subfun(m,n,i,j-1,s,res);
            s.resize(s.size()-1);
            m[i][j]=1;
        }
        if(j+1<n && m[i][j+1]==1){
            s+="R";
            m[i][j]=0;
            subfun(m,n,i,j+1,s,res);
            s.resize(s.size()-1);
            m[i][j]=1;
        }
        if(i>0 && m[i-1][j]==1){
            s+="U";
            m[i][j]=0;
            subfun(m,n,i-1,j,s,res);
            s.resize(s.size()-1);
            m[i][j]=1;
        }
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends