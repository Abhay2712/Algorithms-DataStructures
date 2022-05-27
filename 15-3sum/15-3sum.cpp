class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<3) return {};
        if(nums[0] > 0) return {};
        
        unordered_map<int,int>map;
        vector<int>temp;
        set<vector<int>>s;
        for(int i=0;i<nums.size();i++){
            map[-nums[i]]=i;
        }
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(nums[i]>0) break;
            for(int j=i+1;j<n-1;j++){
                if(map[nums[i]+nums[j]] && map[nums[i]+nums[j]]>j){
                    temp={nums[i],nums[j],-nums[i]-nums[j]};
                    s.insert(temp);
                }
            }
        }
        vector<vector<int>>res(s.begin(),s.end());
        return res;
    }
};