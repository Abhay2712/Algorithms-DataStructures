
class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;
        stack<int>st;
        for(auto i:s){
            if(i=='(')
                st.push(0);
            else if(i==')')
                st.pop();
            
            if(st.size()>maxi) maxi=st.size();
        }
        return maxi;
    }
};