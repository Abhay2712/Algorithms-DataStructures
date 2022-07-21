class Solution {
public:
    int subfun(int i,int ticket,vector<int>&days,vector<int>&cost,vector<vector<int>>&dp){
        if(i>=days.size()) return 0;
        if(dp[i][ticket]!=-1) return dp[i][ticket];
        
        if(days[i]>ticket){
            int t1=cost[0]+subfun(i+1,days[i],days,cost,dp);
            int t2=cost[1]+subfun(i+1,days[i]+6,days,cost,dp);
            int t3=cost[2]+subfun(i+1,days[i]+29,days,cost,dp);
            return dp[i][ticket]=min(t1,min(t2,t3));
        }
        else return dp[i][ticket]=(subfun(i+1,ticket,days,cost,dp));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int max_validity = days[n-1] + 30;
        vector<vector<int>> dp(n, vector<int>(max_validity+1, -1));
        return subfun(0,0,days,costs,dp);
    }
};