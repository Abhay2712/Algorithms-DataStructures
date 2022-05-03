class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>ans;
        ans=nums;
        sort(ans.begin(),ans.end());
        if(ans==nums) return 0;
        int n=nums.size();
        bool f=1;
        int s=0,e=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=ans[i]){
                if(f){
                    f=0;
                    s=i;
                }
                else e=i;
            }
        }
        
        return e-s+1;
    }
};