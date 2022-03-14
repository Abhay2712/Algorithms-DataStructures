class Solution {
public:
    int mod=1000000007;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>pnc(nums.size(),1);
        for(int i=1;i<nums.size();i++){         //there will be 2 options for each- take or not take
            pnc[i]=2*pnc[i-1]%mod;              //so using pnc and dp find all the possible outputs and save in an array
        }
        int i=0,j=nums.size()-1,count=0;
        
        while(i<=j){
            if(nums[i]+nums[j]<=target) {
                count=(count+pnc[j-i])%mod;     //using 2 pointers if found add the permutations from array
                i++;                            //else just reduce the position of maximum element
            }
            else j--;
        }
        return count%mod;
    }
};