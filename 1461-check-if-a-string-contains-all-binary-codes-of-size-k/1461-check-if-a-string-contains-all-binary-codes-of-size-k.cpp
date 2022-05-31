class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int j=0,n=s.size();
        int count=0;
        unordered_map<string,int>map;
        while(j<n-k+1){
            if(!map[s.substr(j,k)]){ 
                count++;
                // cout<<s.substr(j,k)<<" ";
                map[s.substr(j,k)]=1;
            }
            j++;
        }
        if(count==pow(2,k)) return true;
        return false;
    }
};