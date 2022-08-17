class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0,o=0,t=0;
        for(auto i:nums){
            if(!i) z++;
            else{
                if(i==1){
                    o++;
                }
                else{
                    t++;
                }
            }
        }
        cout<<z<<" "<<o<<" "<<t;
        int i=0;
        while(z>0){
            nums[i++]=0;
            z--;
        }
        while(o>0){
            nums[i++]=1;
            o--;
        }
        while(t>0){
            nums[i++]=2;
            t--;
        }
    }
};