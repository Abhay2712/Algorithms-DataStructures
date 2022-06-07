class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        vector<vector<int>>res;
        
        subfun(1,n,k,temp,res);
        return res;
    }    
        void subfun(int i,int n, int k,vector<int>&temp,vector<vector<int>>&res){
            if(k==0){
                res.push_back(temp);
                return;
            }
            if(i<=n){ 
                temp.push_back(i);
                subfun(i+1,n,k-1,temp,res);
                temp.pop_back();
                subfun(i+1,n,k,temp,res);
            }
            return;
    }
    
};