class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>q1;
        for(auto i:nums){
            q1.push(i);
        }
        int a1=q1.top()-1; q1.pop();
        int b1=q1.top()-1; q1.pop();
        return a1*b1;
        
        
    }
};