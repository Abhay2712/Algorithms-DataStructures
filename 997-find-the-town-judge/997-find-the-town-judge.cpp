class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts (n+1, 0) ;
        vector<int> trustedby (n+1, 0);

        for(int i = 0 ; i< trust.size() ; i++)
        {
            trusts[trust[i][0]]++ ;
            trustedby[trust[i][1]] ++ ;
        }
        
        for(int i = 1 ; i<=n ; i++)   
            if(trusts[i] == 0 && trustedby[i] == n-1) return i ;
        
        return -1 ; 
    }
};