class Solution {
public:
    string removeDuplicates(string s) {
        string res = "0";
        for(int i=0; i<s.length(); i++){
            if(res.back() != s[i]){
                res += s[i];
            }else{
                while(res.back() == s[i]) {
                    res.pop_back();
                }
            }
        }
        return res.substr(1);
    }
};