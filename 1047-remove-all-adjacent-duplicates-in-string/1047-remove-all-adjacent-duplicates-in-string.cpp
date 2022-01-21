class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        
        for( int i=0 ; i<s.length() ; i++){
            
            if(ans.size() && s[i] == ans.back() )
                ans.pop_back();
            else
                ans.push_back(s[i]);
        }
        return ans ;
    }
};