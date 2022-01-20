// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>res;
		    subfun(res,S,0);
		    sort(res.begin(),res.end());
		    return res;
		}
		
		void subfun(vector<string>&res,string S,int ind){
        if(ind==S.size()){
            res.push_back(S);
            return;
        }
        
        for(int i=ind;i<S.size();i++){
                swap(S[ind],S[i]);
                subfun(res,S,ind+1);
                swap(S[ind],S[i]);
        }        
    }
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends