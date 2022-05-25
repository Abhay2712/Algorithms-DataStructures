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
        // [ 6, 1, 8, 5, 7, 3, 8 ]1 3 7 8  2 5 5 7
        for(auto i:env){
            int ele = i[1];
            int idx = lower_bound(lis.begin(), lis.end(), ele) - lis.begin();
            cout<<i[0]<<i[1]<<"\n";
            if(idx >= lis.size()) lis.push_back(ele);
            else{ 
                lis[idx] = ele;
                // cout<<idx<<ele<<i[0]<<i[1]<<"\n";
        }}
        
        for(auto i:lis)
            cout<<i;
        
        return lis.size();
    }
};