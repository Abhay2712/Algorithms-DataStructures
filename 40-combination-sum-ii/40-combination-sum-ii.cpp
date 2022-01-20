class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>ds; 
        sort(candidates.begin(),candidates.end());
        subfun(res,candidates,ds,target,0,0);
        return res;
        
    }
    
    void subfun(vector<vector<int>>&res,vector<int>&candidates,vector<int>&ds,int target,int i,int prev){
            if(i==candidates.size()){
                if(target==0){
                    res.push_back(ds);
                }
                return;
            }
            if(candidates[i]<=target){
                ds.push_back(candidates[i]);
                subfun(res,candidates,ds,target-candidates[i],i+1,prev);
                prev=candidates[i];
                ds.pop_back();
            }    
            
            while((i+1<candidates.size()) && candidates[i+1]==prev){
                i++;
            }
            
            
            subfun(res,candidates,ds,target,i+1,prev);
            
        }
};