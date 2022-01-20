class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>all={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int l=digits.length();
        vector<string>res;
        int i=0;
        string str="";
        if(l==0) 
            return(res);
        subfun(i,str,l,res,digits,all);
        return res;
    }
    
    void subfun(int i,string str,int l,vector<string>&res,string digits,vector<string>&all){
            if(i==l){
                res.push_back(str);
                return;
            }
            int n=(digits[i])-'0';
            for(auto j:all[n-2]){
                str+=j;
                i++;
                subfun(i,str,l,res,digits,all);
                str.pop_back();
                i--;
            
        }
            
        }
    
};