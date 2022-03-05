class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
		int n = 10001;    
        if (nums.size() == 1) return nums[0];

        vector<int> map(n, 0);
        
        for (auto &num: nums) {
            map[num] += num;
        }
        int a = map[0];
        int b = max(a,map[1]);
        
        for (int i = 2; i < n; i++) {
            int cur = max(b,a+map[i]);
            a=b;
            b=cur;
            
        }
        return max(a,b);     
    }
};