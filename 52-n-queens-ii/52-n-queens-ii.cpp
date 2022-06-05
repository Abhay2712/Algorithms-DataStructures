class Solution {
public:
    int totalNQueens(int n) {
        int res=0;
        vector<string>board(n);
        //for initializing the board as empty
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        //till here
        vector<int>lrow(n,0),udog(2*n-1,0),ldog(2*n-1,0);
        subfun(res,board,0,n,lrow,udog,ldog);
        return res;
    }
    
    void subfun(int &res,vector<string>&board,int col,int n,vector<int>&lrow,vector<int>&udog,vector<int>&ldog){
        if(col==n){
            res+=1;
            return;
        }
        for(int row=0;row<n;row++){
            if(lrow[row]==0 &&ldog[row+col]==0 && udog[n-1+col-row]==0){
                board[row][col]='Q';
                lrow[row]=1;
                ldog[row+col]=1;
                udog[n-1+col-row]=1;
                subfun(res,board,col+1,n,lrow,udog,ldog);
                board[row][col]='.';
                lrow[row]=0;
                ldog[row+col]=0;
                udog[n-1+col-row]=0;
            }
        }
    }
};