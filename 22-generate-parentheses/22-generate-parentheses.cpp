class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int i=0,j=0;
        string temp="";
        vector<string>res;
        subfun(i,j,n,temp,res);
        return res;
    }
    
    void subfun(int i,int j,int n,string &temp,vector<string>&res){
        if(i>n) return;
        if(i==j && i==n){
            res.push_back(temp);
            return;
        }
        temp+='(';
        subfun(i+1,j,n,temp,res);
        temp.pop_back();
        if(j<i){
            temp+=')';
            subfun(i,j+1,n,temp,res);
            temp.pop_back();
        }
        return;
    }
};