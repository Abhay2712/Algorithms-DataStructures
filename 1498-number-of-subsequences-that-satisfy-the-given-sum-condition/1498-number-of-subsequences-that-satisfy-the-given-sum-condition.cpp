class Solution {
public:
    int mod=1000000007;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>pnc(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            pnc[i]=2*pnc[i-1]%mod;
        }
        int i=0,j=nums.size()-1,count=0;
        
        while(i<=j){
            if(nums[i]+nums[j]<=target) {
                // cout<<nums[i]+nums[j]<<" ";
                count=(count+pnc[j-i])%mod;
                i++;
            }
            else j--;
        }
        return count%mod;
    }
};