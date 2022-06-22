// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
        vector<vector<int>> ans;
        void combination(vector<int> &a,vector<int> &res,int sum,int i){
            if(i==a.size()){
                if(sum==0){
                    ans.push_back(res);
                }
            return;
            }
        
        if(a[i]<=sum){
            res.push_back(a[i]);
            combination(a,res,sum-a[i],i);
            res.pop_back();
        }
        
        combination(a,res,sum,i+1);
    }

    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        set<int> s(A.begin(),A.end());
        A.assign(s.begin(),s.end());
        sort(A.begin(),A.end());
        vector<int> res;
        combination(A,res,B,0);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends