class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        vector<int>result(nums.size());
        for (int i = nums.size()-1; i >= 0; i--) {
            if (abs(nums[left]) > nums[right]) {
                result[i] = nums[left] * nums[left];
                left++;
            } else {
                result[i] = nums[right] * nums[right];
                right--;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = result[i];
        }
        return result;
    }
};