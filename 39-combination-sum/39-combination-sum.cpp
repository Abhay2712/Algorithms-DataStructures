class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>ds; 
        subfun(res,candidates,ds,target,0);
        return res;
        
    }
    
    void subfun(vector<vector<int>>&res,vector<int>&candidates,vector<int>&ds,int target,int i){
            if(i==candidates.size()){
                if(target==0){
                    res.push_back(ds);
                }
                return;
            }
            if(candidates[i]<=target){
                ds.push_back(candidates[i]);
                subfun(res,candidates,ds,target-candidates[i],i);
                ds.pop_back();
                
            }
            subfun(res,candidates,ds,target,i+1);
            
        }
};