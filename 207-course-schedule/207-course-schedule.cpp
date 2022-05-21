class Solution {
public:
    bool dfs(vector<int> adj[],vector<bool> &vis,int start,vector<bool> &ancestor)
       {    vis[start]=true;
            ancestor[start]=true;
            for(auto node: adj[start])
              {      if(!vis[node])
                       {      if(dfs(adj,vis,node,ancestor))
                                   return true;             
                       }
                    else if(ancestor[node])
                      return true;
              }
         ancestor[start]=false;
         return false;
     }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        bool ans=true;
        vector<int> adj[numCourses];
        vector<bool> vis(numCourses,false);
        vector<bool> ancestor(numCourses,false);
        
         for(int i=0;i<prerequisites.size();i++)
         {  
             adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
          }
      for(int i=0;i<numCourses;i++)
         {    if(!vis[i])
                  { if(dfs(adj,vis,i,ancestor))
                       return false;  
                  }
        }
        return true;      
    }
};