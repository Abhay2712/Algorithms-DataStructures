class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string>res(score.size());
        priority_queue<pair<int,int>>q;
        for(int i=0;i<score.size();i++){
            q.push({score[i],i});
        }
        int n=1;
        while(!q.empty()){
            int a=q.top().second;
            q.pop();
            if(n==1) res[a]="Gold Medal";
            else if(n==2) res[a]="Silver Medal";
            else if(n==3) res[a]="Bronze Medal";
            else res[a]=to_string(n);
            n++;
        }
        return res;
    }
};