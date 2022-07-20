class Solution 
{
    public :
        // l is copied value and i is current length
        int count(int i, int n, int l, vector<vector<int>>& dp )
        {
            if( i > n )
                return 1e7 ;
				
            else if(!(n-i))
                return 0 ;
				
            else if( dp[i][l] )
                return dp[i][l] ;
				
            else
            {
                int copy  = 2 + count(i+i,n,i,dp); //copy current and paste so i becomes double
                int paste = 1 + count(i+l,n,l,dp);
				
                return dp[i][l] = min( copy, paste );
            }
        }
    
        int minSteps( int n ) 
        {            
            vector<vector<int>> dp(n+1,vector<int>(n+1,0));
            return ( n > 1 ? 1 + count(1,n,1,dp) : 0 );
        }
};