class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        for(auto i:nums){
            if(i>0){
                pos.push_back(i);
            }
            else neg.push_back(i);
        }
        vector<int>res;
        for(int i=0;i<pos.size();i++){
            res.push_back(pos[i]);
            res.push_back(neg[i]);
        }
        
        return res;
    }
};