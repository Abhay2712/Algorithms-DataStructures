class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        
        //edge cases
        if(total-target<0) return 0;
        if((total-target)%2==1) return 0;   //NO FRACTIONS
    
        int s2 = (total-target)/2;      //S1-S2=TARGET ->TOTAL-S2-S2=TARGET-> S2=TOTAL-TARGET/2
        vector<vector<int>>dp(n,vector<int>(s2+1,-1));
        
        return subfun(nums,s2,n-1,dp);
    }
    
    int subfun(vector<int>&nums,int target,int i,vector<vector<int>>&dp){
        if(i==0){
            if(target==0 && nums[0]==0) return 2;
            if(target==0 || target == nums[0])
                return 1;
            return 0;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        
        int notTake=subfun(nums,target,i-1,dp);
        int taken=0;
        if(nums[i]<=target){
            taken=subfun(nums,target-nums[i],i-1,dp);
        }
            
        
        return dp[i][target]=notTake+taken;
    }
};