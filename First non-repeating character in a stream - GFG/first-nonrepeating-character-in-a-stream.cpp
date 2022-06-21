// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
string FirstNonRepeating(string A){
    string ans = "";
	queue<char> q;
	int freq[26];
	memset(freq, 0, sizeof(freq));
		    
	freq[A[0]-'a']++;
	ans+=A[0];
	q.push(A[0]);
		    
	for(int i=1;i<A.size();i++){
		freq[A[i]-'a']++;
		if(A[i] == q.front()){
			while(!q.empty() && freq[q.front()-'a']>1)
			{
		       q.pop();
			}
		}else{
		    if(freq[A[i]-'a']==1) q.push(A[i]);
		}
		        
		ans+= (q.empty() ? '#' : q.front());
	}
	return ans;
}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends