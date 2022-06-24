class Solution {
public:
    unordered_map<string,bool>m;
    bool wordBreak(string s, vector<string>& wordDict) {
        if(find(wordDict.begin(),wordDict.end(),s)!=wordDict.end())
            return true;
        if(m.find(s)!=m.end())
            return m[s];
        for(int i=1;i<s.size();i++){
            string left = s.substr(0,i);
            if(find(wordDict.begin(),wordDict.end(),left)!=wordDict.end() && wordBreak(s.substr(i),wordDict)){
                m[s]=true;
                return true;
            }
        }
   
        m[s]=false;
        return false;
    }
    
};