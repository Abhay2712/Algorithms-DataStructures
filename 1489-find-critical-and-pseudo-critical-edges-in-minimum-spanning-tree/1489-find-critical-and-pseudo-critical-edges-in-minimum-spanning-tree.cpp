class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) 
    {   
        //add number to all the adges which we have to print at the end
        for(int i=0;i<edges.size();i++)
        {
            edges[i].push_back(i);
        }
        //sort the edges according to their weight
        sort(edges.begin(),edges.end(),[&](vector<int>a,vector<int> b){return a[2]<b[2];});
        vector<int> critical,pseudo_critical;
        
        //store the cost of building a proper MST in original graph
        int original_cost=buildmst(n,edges,-1,-1);
        
        //now try finding different MST by excluding some edges
        for(int i=0;i<edges.size();i++)
        {
            if(original_cost<buildmst(n,edges,i,-1))  //if cost increases hence the edge is critical
            {
                critical.push_back(edges[i][3]);
            }
            else if(original_cost==buildmst(n,edges,-1,i))    //else if we get the same cost as original
                                                            //this means that the edge is appearing in some
                                                            //MST but not in all 
            {                                              
                pseudo_critical.push_back(edges[i][3]);
            }
        }
        return {critical,pseudo_critical};
    }
        
    //normal kruskal algorithm find function  
    int find(vector<int> &par,int u)
    {
        if(u==par[u])
            return u;
        return par[u]=find(par,par[u]);
    }
    
    //normal kruskal algorithm union function  
    void Union(vector<int> &par,int u,int v)
    {
        int pu=find(par,u),pv=find(par,v);
        par[pu]=pv;
    }
    
    //function to get cost from building MST with some blocked edges
    int buildmst(int n,vector<vector<int>>& edges,int blocked_edge,int pre_edge)
    {
        vector<int> par(n);
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
        int sum=0;
        if(pre_edge!=-1)
        {
            sum+=edges[pre_edge][2];
            Union(par,edges[pre_edge][0],edges[pre_edge][1]);
        }
        for(int i=0;i<edges.size();i++)//mst
        {
            if(i==blocked_edge)
                continue;
            int pu=find(par,edges[i][0]),pv=find(par,edges[i][1]);
            if(pu!=pv)
            {
                par[pu]=pv;
                sum+=edges[i][2];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(find(par,i)!=find(par,0))
                return 1e9;
        }
        return sum;
    }
};