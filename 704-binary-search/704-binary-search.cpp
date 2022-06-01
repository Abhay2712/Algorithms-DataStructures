class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(res>=nums.size() || nums[res]!=target) return -1;
        return res;
    }
};