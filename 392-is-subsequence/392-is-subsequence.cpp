class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l1=s.size();
        int l2=t.size();
        if(s==t) return 1;
        int j=0;
        for(int i=0;i<l2;i++){
            if(s[j]==t[i]) j++;
            if(j==l1) return 1;
        }
        return 0;
    }
};