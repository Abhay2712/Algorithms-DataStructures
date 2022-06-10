class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        int i=32;
        while(n>0){
            if(n%2){
                res+=1<<i-1;
            }
            i--;
            n/=2;
        }
        return res;
    }
};