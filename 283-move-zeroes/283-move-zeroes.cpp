class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int i=0,j=1;
        while(j<nums.size()){
            cout<<i<<j<<" ";
            if(nums[i]==0){
                while(j<nums.size() && !nums[j]){
                    j++;
                }
                if(j<nums.size()) {
                    swap(nums[i],nums[j]); 
                }
            }
            i++;
            j++;
        }
        return ;
    }
};