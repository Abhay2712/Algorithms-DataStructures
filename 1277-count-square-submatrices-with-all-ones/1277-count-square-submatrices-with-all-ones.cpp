class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0) sum+=matrix[i][j];
                else{
                    if(matrix[i][j]){
                        int val=min(matrix[i-1][j],min(matrix[i][j-1],matrix[i-1][j-1]));
                        matrix[i][j]=val+1;
                        sum+=val+1;
                    }
                }
            }
        }
        return sum;
    }
};