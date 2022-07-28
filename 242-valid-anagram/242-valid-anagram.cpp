class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int n=s.size();
        vector<int>v1(26,0),v2(26,0);
        for(int i=0;i<n;i++){
            v1[s[i]-'a']++;
            v2[t[i]-'a']++;
        }
        
        if(v1==v2) return true;
        return false;
    }
};