class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int res = 0;
        for (int a : nums)
            res |= a;
        return res;
    }
};