class Solution {
public:
    int fib(int n) {
        vector<int>arr(n+1,-1);
        return subfun(n,arr);
    }
    
    int subfun(int n,vector<int>&arr){        //dp solution
        if(n<=1) return n;
        if(arr[n]!=-1) return arr[n];
        return arr[n]=(subfun(n-1,arr)+subfun(n-2,arr));       
    }
};