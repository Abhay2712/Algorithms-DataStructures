class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>>arr(n+2,vector<int>(7,0));
        for(int i=0;i<n;i++){
            for(int j=4;j>=0;j--){
                if(j==4 || i==0)
                    arr[i][j]=1;
                else
                    arr[i][j]=arr[i][j+1]+arr[i-1][j];
            }
        }
        int sum=0;
        for(int k=0;k<5;k++){
            sum+=arr[n-1][k];
        }
        return sum;
    }
};