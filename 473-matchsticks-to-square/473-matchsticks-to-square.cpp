class Solution {
public:
    bool solve(int i,vector<int> &arr,vector<bool> &vis,int sum,int rq,int t){
        if(t == 1) return true;
        if(sum == rq) return solve(0,arr,vis,0,rq,t-1);
        if(i == arr.size()) return false;
        
        if(!vis[i] and sum + arr[i] <= rq){
            vis[i] = true;
            if(solve(i+1,arr,vis,sum+arr[i],rq,t)) return true;
            vis[i] = false;                    
        }
        
        return solve(i+1,arr,vis,sum,rq,t);
    }
    bool makesquare(vector<int>& arr) {
        int sum = accumulate(arr.begin(),arr.end(),0);
        if(arr.size() < 4 or sum % 4) return false;
        vector<bool> vis(arr.size());
        return solve(0,arr,vis,0,sum/4,4);
    }
};