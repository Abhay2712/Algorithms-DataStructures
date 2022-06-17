class Solution {
public:
    int subfun(int i,int k,vector<int>&arr,vector<int>&dp){
        int n=arr.size();
        if(i==arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi=INT_MIN;
        int res=INT_MIN;
        int last=min(n,i+k);
        for(int j=i,len=1;j<last;j++,len++){
            maxi=max(maxi,arr[j]);
            int sum=len*maxi+subfun(j+1,k,arr,dp);
            res=max(res,sum);
        }
        return dp[i]=res;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       vector<int>dp(arr.size(),-1);
       return subfun(0,k,arr,dp); 
    }
};