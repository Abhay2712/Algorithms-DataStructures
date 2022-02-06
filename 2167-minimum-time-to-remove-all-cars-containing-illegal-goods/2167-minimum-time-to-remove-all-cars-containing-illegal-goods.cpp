class Solution {
public:
    int minimumTime(string s) {
        int n=s.size();
        
        int max=0,max_t=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') max_t++;
            if(s[i]=='1') max_t--;
            if(max<max_t) max=max_t;
            if(max_t<0) max_t=0;
        }
        return n-max;
    }
};