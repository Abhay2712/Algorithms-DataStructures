class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>dp1(nums.size()-1,-1),dp2(nums.size()-1,-1);
        vector<int>nums1(nums.begin()+1,nums.end());
        vector<int>nums2(nums.begin(),nums.end()-1);
        int max1=sum(nums1.size()-1,nums1,dp1);
        int max2=sum(nums2.size()-1,nums2,dp2);
        return max(max1,max2);
        
    }
    
    int sum(int i,vector<int>&a,vector<int>&dp){
        if (i==0) return a[i];
        else if(i<0) return 0;
        
        if(dp[i]!=-1) return dp[i];
        int pick=a[i]+sum(i-2,a,dp);
        int notpick=sum(i-1,a,dp);
        return dp[i]=(max(pick,notpick));
    }
    
};