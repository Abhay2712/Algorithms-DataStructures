class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>umap;
        for(auto i:magazine){
            umap[i]+=1;
        }
        
        for(auto i:ransomNote){
            if(umap[i]) umap[i]-=1;
            else return false;
        }
        return true;
    }
};