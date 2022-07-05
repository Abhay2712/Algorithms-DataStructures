class Solution {
public:
    
    queue<pair<int, int>> q;
    
    void dfs(vector<vector<int>>& grid, int i, int j) { // for marking the 1st island visited
        
        if (i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j] == 2 or grid[i][j] == 0)
            return;
        
        grid[i][j] = 2; // marking them visited
        q.push({i,j}); // adding them to queue
        
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        bool flag = false;
        
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if (grid[i][j] == 1 and !flag){ // found 1st '1' in the matrix
                    dfs(grid, i, j); // dfs for marking the whole island visited
                    q.push({i,j});
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        
        int d = 0; // dist
        int mindist = INT_MAX; // to store minimum distance
        
        vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        
        while (!q.empty()){
            int n = q.size();
            
            while(n-- > 0){
                auto a = q.front();
                q.pop();

                for (int h=0; h<4; h++) {
                    int x = dir[h][0] + a.first;
                    int y = dir[h][1] + a.second;
                    
                    if (x>=0 and x<grid.size() and y>=0 and y<grid[0].size() and grid[x][y] == 1) { 
                        // if the neighbor is 1, then check if its minimum distance
                        mindist = min(mindist, d);
                    }

                    else if (x>=0 and x<grid.size() and y>=0 and y<grid[0].size() and grid[x][y] == 0) { 
                        // if the neighbor is 0, then mark it visited and add it to queue
                        q.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
            d++; // increasing each level by distance + 1
        }
        
        return mindist; // returning min dist found till end
    }
};
    
    






















//Less optimal code, first we differentiate both the islands and then find the minimum manhattan distance between them
// class Solution {
// public:
//     void dfs(vector<vector<int>>& A, int i, int j, vector <pair<int, int>> &r)
//     {
//         if(i < 0 || j < 0 || i >= A.size() || j >= A[i].size() || A[i][j]==0)
//             return;
//         A[i][j] = 0;
//         r.push_back(make_pair(i,j));
//         dfs(A, i+1, j, r);
//         dfs(A, i-1, j, r);
//         dfs(A, i, j-1, r);
//         dfs(A, i, j+1, r);
//         return;
//     }
//     int shortestBridge(vector<vector<int>>& A) {
//         int count = 0;
//         vector <pair<int, int>> x;
//         vector <pair<int, int>> y;
//         for(int i=0; i<A.size(); i++)
//         {
//             for(int j=0; j<A[i].size(); j++)
//             {
//                 if(A[i][j] == 1)
//                 {
//                     count++;
//                     if(count == 1)
//                     {
//                         dfs(A, i, j, x);   
//                     }
//                     if(count == 2)
//                     {
//                         dfs(A, i, j, y);   
//                     }   
//                 }
//             }
//         }
//         int min_dist = INT_MAX;
//         for(int i=0; i<x.size(); i++)
//         {
//             for(int j=0; j<y.size(); j++)
//             {
//                 int dist = abs(x[i].first - y[j].first) + abs(x[i].second - y[j].second) - 1;
//                 if(dist < min_dist)
//                     min_dist = dist;
//             }
//         }
//         return min_dist;
//     }
// };