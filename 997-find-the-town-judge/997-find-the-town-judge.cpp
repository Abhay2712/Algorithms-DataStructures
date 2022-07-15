class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>recieve(n+1,vector<int>());
        vector<vector<int>>send(n+1,vector<int>());
        for(auto i:trust){
            recieve[i[1]].push_back(i[0]);
            send[i[0]].push_back(i[1]);
        }
        
        for(int i=1;i<=n;i++){
            if(recieve[i].size()==n-1 && send[i].size()==0) return i;
        }
        return -1;   
    }
};