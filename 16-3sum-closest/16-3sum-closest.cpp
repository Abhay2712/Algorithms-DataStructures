class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        int closest=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){ //as j=i+1 max value of i can be n-2
            int j=i+1;
            int k=n-1;
            while(j<k){
                int temp=nums[i]+nums[j]+nums[k];//Temparory sum for comaprison
                if(abs(temp-target) < abs(closest-target) ) closest=temp;
                if(temp>target){
                    k--;                  
                } else if(temp<target){
                    j++;             
                }else return target;// if value already found no need to go for other just return 
            }
            
        }
        return closest;
    }
};