class Solution {
public:
    string reverseStr(string s, int k) {
        int i=1,start,end,last=0,n=s.size()-1; 
        
        while(k*(i)-1<s.size()){    //loop to reverse current k elements
            start=k*(i-1);
            end=k*i-1;
            while(start<end)
                swap(s[start++],s[end--]);
            i+=2;                   //added 2 to skip next k elements
            last=k*(i-1);           //in case next k elements are not available to reverse store the last element index 
        }
        
        while(last<n){  //reverse the remaining elements from last to end of string
            swap(s[last++],s[n--]);
        }
        return s;
    }
};