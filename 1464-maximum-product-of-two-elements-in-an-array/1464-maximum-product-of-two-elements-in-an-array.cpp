class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int max1 = INT_MIN; //largest number
        int max2 = INT_MIN; //second largest number
        
        for(int i=0; i<nums.size(); i++)
        {
            int val = nums[i];
            
            if(val > max1) //value greater than max1, update second largest with largest so far 
            {
                max2 = max1;
                max1 = val;
            }
            
            else if(val <= max1 && val > max2) //equality holds as max1 = max2 can be possible
            {
                max2 = val;
            }
        }
        
        return (max1-1)*(max2-1);
    }
};