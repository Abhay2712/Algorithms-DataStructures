class Solution {
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>>res;
        vector<int>ds;
        int n=arr.size();
        subfun(arr,res,n,0,ds);
        return res;
    }
    
    void subfun(vector<int>&arr,vector<vector<int>>&res,int n,int i,vector<int>ds){
        if(i==n){
            res.push_back(ds);
            return;
        }
        ds.push_back(arr[i]);
        subfun(arr,res,n,i+1,ds);
        ds.pop_back();
        subfun(arr,res,n,i+1,ds);
    }
};