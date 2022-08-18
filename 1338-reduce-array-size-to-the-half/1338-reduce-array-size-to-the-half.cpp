class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>um;
        for(auto i:arr){
            um[i]++;
        }
        
        priority_queue<int>q;
        for(auto i:um){
            q.push(i.second);
        }
        
        int count=0,total=0;
        while(!q.empty()){
            count++;
            total+=q.top();
            q.pop();
            if(total>=n/2) return count;
        }
        return 0;
    }
};