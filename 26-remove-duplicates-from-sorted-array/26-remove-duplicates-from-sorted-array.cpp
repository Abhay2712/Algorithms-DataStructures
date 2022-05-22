class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
	int len = nums.size(), i, j; // two pointer, i slow, j fast

	for(i = 0, j = 1; j < len; ++j) {
		if(nums[i] != nums[j])
			nums[++i] = nums[j]; 
	}

	return i + 1; 
}
};