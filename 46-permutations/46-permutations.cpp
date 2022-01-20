class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>ds;
        int n=nums.size();
        int freq[n];
        for(int i=0;i<n;i++) freq[i]=0;
        subfun(res,nums,ds,freq);
        return res;
    }
    
    void subfun(vector<vector<int>>&res,vector<int>&nums,vector<int>&ds,int freq[]){
        if(ds.size()==nums.size()){
            res.push_back(ds);
        }
        
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                subfun(res,nums,ds,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
        
    }
};