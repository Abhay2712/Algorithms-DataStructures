class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        vector<int>temp{0};
        subfun(0,graph,res,temp);
        return res;
    }
    
    void subfun(int i,vector<vector<int>>& graph,vector<vector<int>>&res,vector<int>&temp){
        if(i==graph.size()-1) res.push_back(temp);
        
        for(auto j:graph[i]){
            temp.push_back(j);
            subfun(j,graph,res,temp);
            temp.pop_back();
        }
    }
};