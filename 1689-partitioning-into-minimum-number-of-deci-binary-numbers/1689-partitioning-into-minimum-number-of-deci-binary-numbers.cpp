class Solution {
public:
    int minPartitions(string n) {
        int maxi=0;
        for(char i:n){
            maxi=max(i-'0',maxi);
            if(maxi==9) return 9;
        }
        return maxi;
    }
};