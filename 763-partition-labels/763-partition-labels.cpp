class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<int,int>m1,m2;
        vector<int>ans;
        int n=s.size();
        for(auto i:s){
            m1[i]++;
        }
        int count=0,prev=0,z=0;
        for(int i=0;i<n;i++){
            m2[s[i]]++;
            if(m2[s[i]]==1) count++;
            
            if(m2[s[i]]==m1[s[i]]) count--;
            if(count==0) {
                ans.push_back(i-prev+1);
                prev=i+1;
                         }
        }
        return ans;
    }
};