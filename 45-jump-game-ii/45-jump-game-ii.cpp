class Solution {
public:
    int jump(vector<int>& nums) {
	vector<int> dp(nums.size(), 10001); 
	return solve(0,nums, dp);
}

int solve(int pos,vector<int>& nums, vector<int>& dp) {
	if(pos >= (nums).size() - 1) return 0; 
	if(dp[pos] != 10001) return dp[pos]; 
	
	for(int j = 1; j <= nums[pos]; j++)
		dp[pos] = min(dp[pos], 1 + solve(pos + j, nums, dp ));        
	return dp[pos];
}
};