class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i,j;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(board[i][j]=='.') continue;
                if(row(board,i,board[i][j])&&col(board,j,board[i][j])&&grid(board,i-i%3,j-j%3,board[i][j])) continue;
                else return 0;
            }
        }
        return 1;
    }
    bool row(vector<vector<char>>& board,int i, char ch)
    {
        int cnt=0,j;
        for(j = 0;j<9;j++)
        {
            if(board[i][j]==ch)cnt++;
            if(cnt==2) return 0;
        }
        return 1;
    }
    bool col(vector<vector<char>>& board,int j, char ch)
    {
        int cnt =0,i;
        for(i=0;i<9;i++)
        {
            if(board[i][j]==ch)cnt++;
            if(cnt==2) return 0;
        }
        return 1;
    }
    bool grid(vector<vector<char>>& board, int i1, int j1,char ch)
    {
        int cnt=0,i,j;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(board[i+i1][j+j1]==ch)cnt++;
                if(cnt==2) return 0;
            }
        }
        return 1;
    }
};