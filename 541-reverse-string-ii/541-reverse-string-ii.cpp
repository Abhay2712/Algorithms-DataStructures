class Solution {
public:
    string reverseStr(string s, int k) {
        int i=1,start,end,last=0,n=s.size()-1; 
        while(k*(i)-1<s.size()){
            start=k*(i-1);
            end=k*i-1;
            while(start<end)
                swap(s[start++],s[end--]);
            i+=2;
            last=k*(i-1);
        }
        
        while(last<n){
            swap(s[last++],s[n--]);
        }
        return s;
    }
};