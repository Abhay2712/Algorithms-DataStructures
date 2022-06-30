class Solution {
public:
    unordered_map<int,int>map;
    
    bool isHappy(int n) {
        if(n==1) return 1;
        if(n==0 || map[n]==1) return 0;
        int val=0;
        map[n]=1;
        while(n){
            int v=n%10;
            n/=10;
            val+=v*v;
        }
        cout<<val<<" ";
        return isHappy(val);
    }
};