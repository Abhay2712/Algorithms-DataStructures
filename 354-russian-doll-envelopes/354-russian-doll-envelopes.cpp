class Solution {
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();
        
        sort(env.begin(), env.end(), cmp);
        
        vector<int> lis;
        for(auto i:env){
            int ele = i[1];
            int idx = lower_bound(lis.begin(), lis.end(), ele) - lis.begin();
        
            if(idx>=lis.size()) lis.push_back(ele);
            else{ 
                lis[idx] = ele;
        }}
        
        return lis.size();
    }
};