class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int sum = 0;
        vector<int>prefixSum(n);
        map<int, int> sumFreq;
        
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            prefixSum[i] = sum;
            sumFreq[sum]++;
        }
        
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int find = k + prefixSum[i] - nums[i];
            res += sumFreq[find];
            sumFreq[prefixSum[i]]--;
        }
        return res;
    }
};