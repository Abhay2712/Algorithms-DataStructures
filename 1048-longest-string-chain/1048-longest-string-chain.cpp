class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &a,string &b){
            return a.size()<b.size();
        });
        int n=words.size();
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j]) && dp[j]+1>dp[i])
                    dp[i]=1+dp[j];
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
        
    }
    
    bool check(string &a,string &b){
        if(a.size()!=b.size()+1) return 0;
        int i=0,j=0;
        while(i<a.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else i++;
        }
        if(i==a.size() && j==b.size()) return 1;
        return 0;
    }
};