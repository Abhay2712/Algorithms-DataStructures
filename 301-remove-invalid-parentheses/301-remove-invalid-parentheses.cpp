class Solution {
public:

	/*Functtion to calculate mismatched bracket*/
	int minvalid(string s){
		stack<int> st;
		for(auto it: s){
			if(it == '(')   st.push(it);
			else if(it == ')'){
				if(!st.empty() && st.top() == '(')
					st.pop();
				else    st.push(it);
			}
		}
		return st.size();
	}
	
	
	void solve(string s, vector<string>& ans, map<string, bool>& mpp, int removal){
		/*If the string is already present in the map return back*/
		if(mpp[s])  return;
		
		/*If the string is not prensent in the map add it, and give the value of the string TRUE*/
		else    mpp[s] = true;

		if(removal==0){
			/*Even though removal becomes zero we still have to check its validity*/
			int n = minvalid(s);
			if(n == 0)
				ans.push_back(s);
			return;
		}
		
		for(int i=0;i<s.length();i++){
			string left = s.substr(0,i);
			string right = s.substr(i+1);
			/*Excluding the ith element*/
			solve(left+right, ans, mpp, removal-1); 
		}
	}

	vector<string> removeInvalidParentheses(string s) {
		int removal = minvalid(s);
		vector<string> ans;
		map<string, bool> mpp;
		solve(s, ans, mpp, removal);
		return ans;
	}
};