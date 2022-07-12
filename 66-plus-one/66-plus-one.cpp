class Solution {
public:
    vector<int> plusOne(vector<int>& digit) {
        int n=digit.size();
        int carry=1;
        for(int i=n-1;i>=0;i--){
            digit[i]+=carry;
            carry=digit[i]/10;
            digit[i]%=10;
        }
        if(carry==1) digit.insert(digit.begin(),1);
        return digit;
    }
};