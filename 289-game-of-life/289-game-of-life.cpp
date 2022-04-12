class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        int c1,c2;
        vector<vector<int>>board1=board;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){  
                c1=0;
                c2=0;
                if(j>0 && i>0){
                    if(board[i-1][j-1]==0) c1++;
                    else c2++;
                }
                if(j>0){
                    if(board[i][j-1]==0) c1++;
                    else c2++;
                }
                    
                if(i>0){
                    if(board[i-1][j]==0) c1++;
                    else c2++;
                }
                    
                if(j<m-1){
                    if(board[i][j+1]==0) c1++;
                    else c2++;
                }
                if(i<n-1){
                    if(board[i+1][j]==0) c1++;
                    else c2++;
                }
                if(j>0 && i<n-1){
                    if(board[i+1][j-1]==0) c1++;
                    else c2++;
                }
                if(i>0 && j<m-1){
                    if(board[i-1][j+1]==0) c1++;
                    else c2++;
                }
                
                if(j<m-1 && i<n-1){
                    if(board[i+1][j+1]==0) c1++;
                    else c2++;
                }
                
                cout<<c1<<" "<<c2<<" ";
                if(c2<=1) board1[i][j]=0;
                else if(board[i][j]==1 && (c2==2 ||c2==3)) board1[i][j]=1; 
                else if(c2>3) board1[i][j]=0;
                else if(c2==3) board1[i][j]=1;
            }
        }
        board=board1;
    }
};