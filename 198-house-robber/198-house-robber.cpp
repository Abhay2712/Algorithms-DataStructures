class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev1=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int notTake=prev1;
            int res=max(take,notTake);
            
            prev2=prev1;
            prev1=res;
        }
        return prev1;
    }
};

/*recursion code
int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return(sum(nums.size()-1,nums,dp));
        
    }
    
    int sum(int i,vector<int>&a,vector<int>&dp){
        if (i==0) a[i];
        else if(i<0) return 0;
        
        if(dp[i]!=-1) return dp[i];
        int pick=a[i]+sum(i-2,a,dp);
        int notpick=sum(i-1,a,dp);
        return dp[i]=(max(pick,notpick));
    }
*/