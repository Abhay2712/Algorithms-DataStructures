class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        string temp;
        int n=s.size();
        vector<string>res;
        
        subfun(0,n,s,temp,res);
        return res;
    }
    
    void subfun(int i,int n,string s,string temp,vector<string>&res){
        if(!n){
            res.push_back(temp);
            return;
        }
        
        if(s[i]>='0' && s[i]<='9') {
            temp+=s[i];
            subfun(i+1,n-1,s,temp,res);
        }
        else{
            temp+=tolower(s[i]);
            subfun(i+1,n-1,s,temp,res);
            temp.pop_back();
            temp+=toupper(s[i]);
            subfun(i+1,n-1,s,temp,res);
            // temp.pop_back();
        }
    }
};