//using map and priority queue
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> N;
        priority_queue<pair<int, int>> Q;
        for(int i=0;i<nums.size();i++){
            N[nums[i]]++;
        }
        
        for(auto it=N.begin();it!=N.end();it++)
        {
            Q.push({it->second,it->first});
        }
        
        vector<int> R;
        
       while(k--){
            R.push_back(Q.top().second);
            Q.pop();
        }
        
        return R;
    }
};

// using 2 maps
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         map<int,int>maps;
//         map<int,vector<int>>maps1;
//         for(int i=0;i<nums.size();i++){
//             maps[nums[i]]++;
//         }
        
//         for(auto i:maps){
//             maps1[-i.second].push_back(i.first);
//         }
        
//         vector<int>ans;
//         for(auto i:maps1){
//             for(auto j:i.second){
//                 if(k--) ans.push_back(j);    
//                 else break;
//             }
//             if(!k) break;
//         }
//         return ans;
//     }
// };