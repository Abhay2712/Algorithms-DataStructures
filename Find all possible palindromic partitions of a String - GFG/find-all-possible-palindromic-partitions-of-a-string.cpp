// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<string>> allPalindromicPerms(string s) {
        vector<vector<string>>res;
        vector<string>ds;
        subfun(res,ds,s,0);
        return res;
        
    }
    
    void subfun(vector<vector<string>>&res,vector<string>&ds,string s,int ind){
        
        if(ind==s.size()){
            res.push_back(ds);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPal(s,ind,i)){
                ds.push_back(s.substr(ind,i-ind+1));
                subfun(res,ds,s,i+1);
                ds.pop_back();
            }
        }
    }
    
    bool isPal(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return 0;
            }
        }
        return 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends