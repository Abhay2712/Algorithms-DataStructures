class Solution {
private:
    void solve(vector<int>& nums,set<vector<int>> &ans,vector<int> t){
        if(t.size()==nums.size()){           
            ans.insert(t);              
            return ;
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=11){            // check if the element is already included
                int j=nums[i];
                nums[i]=11;        // make the current ele to 11 so that it is not inserted in next call
                t.push_back(j);      
                solve(nums,ans,t);  
                nums[i]=j;      // backtrack 
                t.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;          //to store unique permutations
        vector<vector<int>> ans;
        
        solve(nums,s,{});
        
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};