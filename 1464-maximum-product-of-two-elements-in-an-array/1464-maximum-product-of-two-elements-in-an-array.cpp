class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>q1;
        priority_queue<int,vector<int>,greater<int>>q2;
        for(auto i:nums){
            q1.push(i);
            q2.push(i);
        }
        int a1=q1.top()-1; q1.pop();
        int b1=q1.top()-1; q1.pop();
        int a2=q2.top()-1; q2.pop();
        int b2=q2.top()-1; q2.pop();
        return max(a1*b1,a2*b2);
        
        
    }
};