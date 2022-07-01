// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    //at any point k, matrix[i][j] stores min cost to reach from i to j via k intermediate nodes
        int v=matrix.size();
        for(int k=0;k<v;k++){ //vertex as intermediate 
            for(int i=0;i<v;i++){ //all vertex as source one by one
              for(int j=0;j<v;j++){ //destination 
                if(matrix[i][k]==-1 || matrix[k][j]==-1){
                    continue;
                }
                int cur=matrix[i][k]+matrix[k][j];
                
                if(matrix[i][j]==-1){
                    matrix[i][j]=cur;
                }
                
                else matrix[i][j]=min(matrix[i][j],cur);
              }
            }
        }
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends