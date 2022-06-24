class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>count(100,0);
        int ele;
        for(auto i:s){
            ele=i-'A';
            count[ele]++;
        }
        
        int total=0;
        bool flag=0;
        for(auto i:count){
            if(i%2) {
                total+=i-1;
                flag=1;
            }
            else total+=i;
        }
        
        if(flag) return total+1;
        return total;
    }
};