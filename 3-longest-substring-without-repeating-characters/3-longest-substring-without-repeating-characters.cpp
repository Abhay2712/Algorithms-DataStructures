class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
        if(s.size()==1) return 1;
        unordered_map<char,int>map;
        map[s[0]]=1;
        int i=0,j=1;
        int size=0;
        while(i<=j && j<s.size()){
            cout<<i<<j<<"\n";
            if(map[s[j]]==0){
                map[s[j]]=1;
                j++;
            }
            else{
                while(s[i]!=s[j])
                {
                    map[s[i]]=0;
                    i++;
                }
                i++;
                j++;
            }
            size=max(size,j-i);
            
        }
        return size;
    }
};