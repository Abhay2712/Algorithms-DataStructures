class Solution {
public:
    int minBitFlips(int a, int b) {
        int count=0;
        while(a || b){
            if(a%2!=b%2) count++;
            a>>=1;
            b>>=1;
        }
        return count;
    }
};