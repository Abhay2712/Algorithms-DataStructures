class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int s) {
        int r = a.size();
        int c = a[0].size();
        int row=-1;
        
        if(r==1){
          for(int i=0;i<c;i++){
            if(a[0][i]==s)
                return true;
            }
            return false;  
        }
        else if(c==1){
          for(int i=0;i<r;i++){
            if(a[i][0]==s)
                return true;
            }
            return false;  
        }
        
        
        else{
            
        for(int i=0;i<r;i++){
            if(a[i][0]<=s && a[i][c-1]>=s){
                row=i;
            }
        }
        if(row==-1){
            return false;
        }
        for(int i=0;i<c;i++){
            if(a[row][i]==s)
                return true;
        }
        return false; 
        }
                      
    }
};