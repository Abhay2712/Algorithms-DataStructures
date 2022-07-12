class Solution {
public:
    bool solve(int i,vector<int> &arr,vector<bool> &vis,int sum,int req,int t){
        if(t == 1) return true;
        if(sum == req) return solve(0,arr,vis,0,req,t-1); //if we found a sum equal to required, again start from beginning to find another group with the required sum
        if(i == arr.size()) return false;
        
        if(!vis[i] && sum + arr[i] <= req){
            vis[i] = true;
            if(solve(i+1,arr,vis,sum+arr[i],req,t)) return true; //pick
            vis[i] = false;                    
        }
        
        return solve(i+1,arr,vis,sum,req,t); //not pick
    }
    
    bool makesquare(vector<int>&arr) {
        int sum = accumulate(arr.begin(),arr.end(),0);
        if(arr.size() < 4 || sum % 4) return false;   
        vector<bool> vis(arr.size());
        return solve(0,arr,vis,0,sum/4,4);
    }
};