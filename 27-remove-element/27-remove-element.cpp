class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=nums.size()-1;
        int count=0;
        while(i<=j){
            if(nums[i]!=val){ 
                i++;
                count++;
            }
            else{
                swap(nums[i],nums[j]);
                j--;
            }
        }
        return count;
    }
};