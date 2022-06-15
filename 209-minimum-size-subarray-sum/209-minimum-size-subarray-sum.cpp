class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int mini=INT_MAX;
        int sum=0;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            if(sum>=target){ 
                while(sum>=target && i<=j){
                    mini=min(j-i,mini);
                    sum-=nums[i++];
                }
            }
        }
        if(mini==INT_MAX) return 0;
        return mini+1;
    }
};