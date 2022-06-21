class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,n=nums.size();
        while(k && nums[i]<0 && i<n ){
            k--;
            nums[i]=-nums[i];
            i++;
        }
        sort(nums.begin(),nums.end());
        if(k%2) nums[0]=-nums[0];
        
        int sum=0;
        return accumulate(nums.begin(),nums.end(),sum);
    }
};