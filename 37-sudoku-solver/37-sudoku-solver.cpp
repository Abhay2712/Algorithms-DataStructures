class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board){
    
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            //if it has blank space
            if(board[i][j] == '.')
            {
                for(char c='1' ; c<='9' ;c++)
                {
                    if(isValid(board,i,j,c))
                    {
                        board[i][j] = c;
                        if(solve(board)==true)//if we found answer then no need further
                           return true;
                        else
                            board[i][j] = '.';//else removing the char value
                    }
                }
                return false; //tho its empty but we cant enter any value return false
            }
        }
    }
    return true;
    
}

bool isValid(vector<vector<char>>& board,int row,int col, char c)
{
    for(int i=0;i<board.size();i++)
    {
        //for val check in row, row is stable
        if(board[row][i] == c)
        {
            return false;
        }
        //for val check in col, col is stable
        if(board[i][col] == c)
        {
            return false;
        }
        //for the 3x3 matrix
        if(board[3*(row/3)+i/3][3*(col/3)+i%3] == c)
        {
            return false;
        }
    }
    return true;
}
};