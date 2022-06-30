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

//without hashmap
// class Solution {
// public:
//     bool isHappy(int n) {
//         while (n != 1 && n != 4) {
//         int totalSum = 0;
//         while (n > 0) {
//             int d = n % 10;
//             n = n / 10;
//             totalSum += d * d;
//         }
//         n=totalSum;
//         }
//         return n == 1;  
//     }
// };