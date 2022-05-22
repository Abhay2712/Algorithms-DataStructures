class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
	int len = nums.size(), i=0, j; // two pointer, i slow, j fast

	for(j = 1; j < len; ++j) {
		if(nums[i] != nums[j])
			nums[++i] = nums[j]; // move i only if you find a unique element
	}
	return i + 1; 
    }
};