class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int n=maze.size();
        int m=maze[0].size();
        queue<vector<int>>q;
        q.push(e);
        maze[e[0]][e[1]]='+';
        vector<vector<int>>dirs{{-1,0},{1,0},{0,-1},{0,1}};
        int d=0;
        
        while(!q.empty()){
            int p=q.size();
            d++;
            while(p-- >0){
                vector<int>temp=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int x=temp[0]+dirs[i][0];
                    int y=temp[1]+dirs[i][1];
                    
                    if(x<0 || y<0 || x>=n || y>=m || maze[x][y]=='+') continue;
                    else if(x==0 || y==0 || x==n-1 || y==m-1) return d;
                    else{
                        maze[x][y]='+';
                        q.push({x,y});
                    }
                }
            }
        }
        return -1;
    }
};