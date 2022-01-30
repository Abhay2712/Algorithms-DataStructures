class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        int start=n-k;
        vector<int>res;
        
        while(res.size()!=n){
            res.push_back(nums[start%n]);
            start++;            
        }
        nums=res;
        
        
    }
};