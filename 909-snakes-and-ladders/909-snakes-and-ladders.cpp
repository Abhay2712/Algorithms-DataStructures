class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        int toReach=n*n;
        
        //to store values which are visited
        unordered_set<int> s;
        queue<int> q;
        q.push(1);
        s.insert(1);
        
        int moves=0;
        
        while(!q.empty())
        {
            int l=q.size();
            for(int j=0;j<l;j++)
            {
                //for every value in q try the next 6 possible places
                int val=q.front();
                q.pop();
                
                //for the next 6 places
                int next;
                for(int k=1;k<=6;k++)
                {
                    next=val+k;
                    int row=(n-1)-(next-1)/n;
                    int col=(next-1)%n;
                    if((n-1-row) %2)
                    {
                    //if the diff between curr row and last row is even 
                        //then the row values gets flipped
                       col= n-1-col;
                    }
                    
                    //there can be ladder or snake
                    if(board[row][col]!=-1)
                        next=board[row][col];
                    if(next==toReach){
                        return moves+1;
                    }
                    if(s.count(next)) continue;
                    s.insert(next);
                    q.push(next);
                }
            }
            moves++;
        }
        return -1;
            
    }
};