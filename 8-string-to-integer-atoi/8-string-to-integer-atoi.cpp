#include<regex>
class Solution {
public:
    int myAtoi(string s) {
        int sign=1;
        bool flag=1;
        double num=0;
        for(auto i:s){
            if(i=='+') {if(flag){sign=1; flag=0;} else break;}
            else if(i=='-') {if(flag){sign=-1; flag=0;} else break;}
            else if(i=='.') break;
            else if(i==' ') {
                if(flag) continue;
                break;
            }
            else if(i-'0'>9 || i-'0'<0) break;
            else{
                flag=0;
                num=num*10+(i-'0');
            }
        }
        num*=sign;
        if(num>=INT_MAX) {return INT_MAX;}
        if(num<=INT_MIN)  return INT_MIN;
        return (int)num;
    }
};