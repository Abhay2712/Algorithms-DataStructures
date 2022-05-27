class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        // if(pos>=nums.size()){
        //     return nums.size();
        // }
        // else return pos;
    }
};