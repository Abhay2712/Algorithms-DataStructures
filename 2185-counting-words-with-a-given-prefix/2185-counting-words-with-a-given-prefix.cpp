class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        int n=pref.size();      
        for(auto i:words){
            if(i.substr(0,n) == pref) 
                count++;                     
        }
        return count;  
    }
};