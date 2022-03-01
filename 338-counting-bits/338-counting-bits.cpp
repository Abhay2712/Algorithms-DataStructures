class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res(n+1,0);
        int i=0;
        while(i<=n){
            res[i]=__builtin_popcount(i);
            i++;
        }
        return res;
    }
};