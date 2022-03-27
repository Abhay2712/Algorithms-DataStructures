class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        int count=0;
        map<int,vector<int>>maps;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1) count++;
            }
            maps[count].push_back(i);
            count=0;
        }
        vector<int>ans;
        
        for(auto i:maps){
            for(int j=0;j<i.second.size();j++){
                ans.push_back(i.second[j]);
                count++;
                if(count==k) break;
            }
            if(count==k) break;
        }
        return ans;
        
    }
};