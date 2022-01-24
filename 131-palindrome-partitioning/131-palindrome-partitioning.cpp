class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>ds;
        subfun(res,ds,s,0);
        return res;
        
    }
    
    void subfun(vector<vector<string>>&res,vector<string>&ds,string s,int ind){
        
        if(ind==s.size()){
            res.push_back(ds);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPal(s,ind,i)){
                ds.push_back(s.substr(ind,i-ind+1));
                subfun(res,ds,s,i+1);
                ds.pop_back();
            }
        }
    }
    
    bool isPal(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return 0;
            }
        }
        return 1;
    }
};