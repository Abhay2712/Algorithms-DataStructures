class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        vector<int>sa1(26,0);
        vector<int>sa2(26,0);
        for(auto i:s1){
            sa1[i-'a']+=1;
        }
        
        int i=0,j=0;
        while(j<s1.size()){
            sa2[s2[j]-'a']++;
            j++;
        }
        
        while(j<s2.size()){
            if(sa1==sa2) return true;
            sa2[s2[i]-'a']--;
            i++;
            sa2[s2[j]-'a']++;
            j++;
        }
        return (sa1==sa2);
    }
};