class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        ans.push_back(nums);
        while(next_permutation(nums.begin(),nums.end()))
            ans.push_back(nums);
        return ans;
    }
};