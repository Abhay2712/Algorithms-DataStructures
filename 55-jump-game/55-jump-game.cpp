class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return subfun(0,nums,dp);
    }
    
    bool subfun(int i,vector<int>& nums,vector<int>&dp){
        if(i>=nums.size()-1) return true;
        if(dp[i]!=-1) return dp[i];
        int val=nums[i];
        while(val){
            if(subfun(i+val,nums,dp)) return dp[i]=1;
            val--;
        }
        return dp[i]=0;   
    }
};