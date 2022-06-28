class Solution {
public:
    
    int minDeletions(string s) {
        unordered_map<char,int>map;
        int maxi=0;
        for(auto i:s){
            map[i]++;
            maxi=max(maxi,map[i]);
        }
        priority_queue<int>q;
        for(auto i:map){
            q.push(i.second);
        }
        
        int res=0;
        while(!q.empty() && maxi>0){
            if(q.top()==maxi){
                q.pop();
                maxi--;
            }
            else if(q.top()>maxi){
                int val=q.top();
                q.pop();
                val-=maxi;
                maxi--;
                res+=val;
            }
            else{
                maxi=q.top()-1;
                q.pop();
            }
        }
        
        while(!q.empty()){
            res+=q.top();
            q.pop();
        }
        
        return res;
    }
};