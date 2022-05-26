class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool flag=0;
        if (n<=0) return false;
        while (n > 0) {
            if(n%2==1){
                if(flag==1) return false;
                else flag=1;
            }
            n/=2;
        }
        return true;
    }
};