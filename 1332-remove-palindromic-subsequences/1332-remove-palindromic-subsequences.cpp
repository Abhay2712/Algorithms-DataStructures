class Solution {
public:
    int removePalindromeSub(string s) {
        string p=s;
        reverse(p.begin(),p.end());
        if(s==p) return 1;
        else return 2;
        
    }
};