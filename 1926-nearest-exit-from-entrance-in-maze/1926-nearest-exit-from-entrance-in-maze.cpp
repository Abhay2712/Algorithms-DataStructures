class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        queue<vector<int>>q;
        q.push(entrance);
        vector<vector<int>>dirs{{-1,0},{1,0},{0,-1},{0,1}};
        int d=0;
        maze[entrance[0]][entrance[1]]='+';
        while(!q.empty()){
            int p=q.size();
            d++;
            while(p-- >0){
                auto temp=q.front();
                q.pop();
                for(auto i:dirs){
                    int x=temp[0]+i[0];
                    int y=temp[1]+i[1];
                    
                    if(x<0 || y<0 || x>=n || y>=m ) {
                        continue;}
                    
                    if((x==0 || y==0 || x==n-1 || y==m-1) && maze[x][y]=='.') return d;
                    else if(x>0 && y>0 && x<n-1 && y<m-1 && maze[x][y]=='.'){
                        maze[x][y]='+';
                        q.push({x,y});
                    }
                    
                }
            }
        }
        return -1;
    }
};