class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>board(n);
        //for initializing the board as empty
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        //till here
        subfun(res,board,0,n);
        return res;
        
    }
    
    void subfun(vector<vector<string>>&res,vector<string>&board,int col,int n){
        if(col==n){
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(safe(row,col,board,n)){
                board[row][col]='Q';
                subfun(res,board,col+1,n);
                board[row][col]='.';
            }
        }
    }
    
    bool safe(int row,int col,vector<string>&board,int n){
        int a=row;
        int b=col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        
        row=a;
        col=b;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        
        row=a;
        col=b;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }
};