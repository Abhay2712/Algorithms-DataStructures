class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        
        unordered_map<int,int>map;
        map[nums[0]]=1;
        int i=0,j=1;
        int size=0;
        int sum=nums[0];
        while(i<=j && j<nums.size()){
            if(map[nums[j]]==0){
                map[nums[j]]=1;
                sum+=nums[j];
            }
            else{
                while(nums[i]!=nums[j])
                {
                    map[nums[i]]=0;
                    sum-=nums[i];
                    i++;
                }
                i++;
            }
            j++;
            size=max(size,sum);
            
        }
        return size;
    }
};