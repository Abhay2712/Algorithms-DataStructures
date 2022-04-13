class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>res(n,vector<int>(n,0));
        int a=0,i,j;
        int count=1;
        while(a<n){
            i=a;
            for(j=a;j<n-a;j++){
                res[i][j]=count++;
            }
            j=n-a-1;
            for(i=a+1;i<n-a;i++){
                res[i][j]=count++;
            }
            i=n-a-1;
            for(j=n-a-2;j>=a;j--){
                res[i][j]=count++;
            }
            j=a;
            for(i=n-a-2;i>=a+1;i--){
                res[i][j]=count++;
            }
            a++;
        }
        
        
        
        
        return res;
    }
};