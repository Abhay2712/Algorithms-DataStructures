class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>ds;
        subfun(res,nums,0);
        return res;
    }
    
    void subfun(vector<vector<int>>&res,vector<int>&nums,int ind){
        if(ind==nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int i=ind;i<nums.size();i++){
                swap(nums[ind],nums[i]);
                subfun(res,nums,ind+1);
                swap(nums[ind],nums[i]);
        }        
    }
};