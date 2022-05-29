class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int end=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(start==end) return {-1,-1};
        return {start,end-1};
    }
};