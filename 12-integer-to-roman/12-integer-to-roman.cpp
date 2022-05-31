class Solution {
public:
    int val[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string roman[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    string intToRoman(int N) {
        string ans = "";
        for (int i = 0; N; i++){
            while (N >= val[i]) {
                ans += roman[i];
                N -= val[i];
            }
        }
        return ans;
    }
};