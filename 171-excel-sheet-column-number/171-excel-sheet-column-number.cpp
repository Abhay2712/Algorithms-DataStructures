class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum=0,ch;
        int l=columnTitle.length()-1;
        for(auto s:columnTitle){
            ch=(int)s-'A'+1;
            sum+=ch*pow(26,l--);
        }
        return sum;
    }
};