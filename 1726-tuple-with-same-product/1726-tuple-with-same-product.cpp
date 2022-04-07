class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        map<int,int>m;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int prod=nums[i]*nums[j];
                if(m[prod]>0) count+=m[prod];
                m[prod]+=1;
            }
        }
        return count*8;
    }
};