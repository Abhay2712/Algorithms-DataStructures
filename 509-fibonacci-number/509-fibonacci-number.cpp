class Solution {
public:
    int fib(int n) {
        int arr[n+1];
        memset(arr,-1,sizeof(arr));
        return subfun(n,arr);
    }
    
    int subfun(int n,int arr[]){        
        if(n<=1) return n;
        if(arr[n]!=-1) return arr[n];
        return arr[n]=(fib(n-1)+fib(n-2));       
    }
};