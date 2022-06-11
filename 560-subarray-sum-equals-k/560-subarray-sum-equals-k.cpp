class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0,sm=0;
        unordered_map<int,int>mp;
        mp[0]++;
        for(int i=0;i<nums.size();i++){
            sm+=nums[i];
            int x=sm;
            if(mp.find(x-k)!=mp.end())
            ans+=mp[x-k];
            mp[x]++;
        }
        return ans;
    }
};