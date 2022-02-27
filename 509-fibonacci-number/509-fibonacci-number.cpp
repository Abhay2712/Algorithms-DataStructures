class Solution {
public:
    int fib(int n) {
        vector<int>arr(n+1,-1);
        // memset(arr,-1,sizeof(arr));
        return subfun(n,arr);
    }
    
    int subfun(int n,vector<int>&arr){        
        if(n<=1) return n;
        if(arr[n]!=-1) return arr[n];
        return arr[n]=(subfun(n-1,arr)+subfun(n-2,arr));       
    }
};