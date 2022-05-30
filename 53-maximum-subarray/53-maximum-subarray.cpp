class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=nums[0],maxo=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>=0){
                if(curr<0){
                curr=0;
                curr+=nums[i];
                }
                else curr+=nums[i];
            }
            else{
                if(curr<nums[i]) curr=nums[i];
                else curr+=nums[i];
            }
            maxo=max(curr,maxo);
        }
        
        return maxo;
    }
};