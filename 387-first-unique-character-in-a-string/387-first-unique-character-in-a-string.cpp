class Solution {
public:
    int firstUniqChar(string str) {
        unordered_map<char,int>maps;
        
        for(int i=0;i<str.size();i++){
            if(maps.find(str[i])!=maps.end()) maps[str[i]]=-1;
            else maps[str[i]]=i;
        }
        
        int mini=INT_MAX;
        for(auto i:maps){
            if(i.second!=-1) mini=min(mini,i.second);
        }
        return mini==INT_MAX?-1:mini;
    }
};