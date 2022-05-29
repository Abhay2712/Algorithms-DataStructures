class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);  
        for(auto i:edges){
            indegree[i[1]]=1; 
        }
        
        vector<int> res;
        for(int i=0;i<n;i++){
            if( indegree[i]==0){
                res.push_back(i); // add the one that is not reachable by other in res 
            }
        }
        return res;
    }
};