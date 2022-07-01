class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>map;
        for(int i=0;i<26;i++){
            map[order[i]]=i;
        }
        
        string str,str1;
        for(int i=0;i<words.size()-1;i++){
            str1=words[i+1];
            str=words[i];
            int m=str1.size();
            int n=str.size();
            bool check=0;
            for(int j=0;j<min(n,m);j++){
                if(str1[j]==str[j]) continue;
                else if(map[str1[j]]>map[str[j]]){ check=1;break;}
                else return false;
            }
            if(!check && m<n) return false;
        }
        return true;
    }
};