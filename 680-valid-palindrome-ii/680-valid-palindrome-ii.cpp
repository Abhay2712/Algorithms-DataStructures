class Solution {
public:
    bool b=0;
    bool validPalindrome(string s) {
        return subfun(0,s.size()-1,s);
    }
    
    bool subfun(int i,int j,string &s){
        if(i>=j ) return 1;
        if(s[i]==s[j])
            return subfun(i+1,j-1,s);
        
        if(!b){
            b=1;
            return (subfun(i+1,j,s) | subfun(i,j-1,s));
            
        }
        
            
        return 0;
    }
};