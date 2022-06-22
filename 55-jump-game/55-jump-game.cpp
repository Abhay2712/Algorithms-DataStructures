class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0;
        for(int i = 0; i < nums.size(); i++)
            if(mx >= i)
                mx = max(mx, i + nums[i]);
        return (mx >= nums.size()-1);
    }
};