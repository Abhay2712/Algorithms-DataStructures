class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> map;  //We use priority queue for lexographic ordering
    vector<string> ans;
    void dfs(string s)
    {
        auto &x=map[s];
        while(!x.empty())
        {
            string to=x.top();
            x.pop();
            dfs(to);
        }
        ans.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &x:tickets)
            map[x[0]].push(x[1]);
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};