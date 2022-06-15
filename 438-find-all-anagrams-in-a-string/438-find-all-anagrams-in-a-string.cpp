class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>map(26,0);
        vector<int>seen(26,0);
        vector<int>res;
        for(auto i:p){
            map[i-'a']++;
        }   
        int len=p.size();
        int n=s.size();
        if(n<len) return res;
        
        
        int i=0,j=len-1;
        for(int a=0;a<=j;a++){
            seen[s[a]-'a']++;
        }
        while(j<n){
            if(seen==map) res.push_back(i);
            seen[s[i]-'a']--;
            if(j+1<n) seen[s[j+1]-'a']++;
            j++;
            i++;
        }
        return res;
        
    }
};