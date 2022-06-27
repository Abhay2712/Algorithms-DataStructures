class Solution {
public:
    int minPartitions(string n) {
        int maxi=0;
        for(auto i:n){
            maxi=max(i-'0',maxi);
        }
        return maxi;
    }
};