class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>a;
        subfun(1,k,n,ans,a);
        return ans;
    }
    
    void subfun(int j,int k,int n,vector<vector<int>>&ans,vector<int>&a){
        if(k==0){
            if(accumulate(a.begin(),a.end(),0)==n)
                ans.push_back(a);
            return;
        }
        if(j>9) return;
        
        a.push_back(j);
        subfun(j+1,k-1,n,ans,a);
        a.pop_back();
        subfun(j+1,k,n,ans,a);
        return;
    }
        
    
};