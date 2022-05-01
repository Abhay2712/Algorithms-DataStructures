class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.size();
        int m=t.size();
        string ans1="",ans2="";
        int s1=0,s2=0,i=n-1,j=m-1;
        while(i>=0 || j>=0){
            if(i>=0){
            if(s[i]=='#') {s1++;}
            else{
                while(i>=0 && s1!=0){
                    if(s[i]=='#') s1++;
                    else s1--;
                    i--;
                    
                }
                if(i>=0)
                    if(s[i]=='#') s1++;
                    else
                        ans1+=s[i];
            }}
            if(j>=0){
            if(t[j]=='#') {s2++;}
            else{
                while(j>=0 && s2!=0){
                    if(t[j]=='#') s2++;
                    else s2--;
                    j--;
                    
                }
                if(j>=0)
                    if(t[j]=='#') s2++;
                    else ans2+=t[j];
            }}
            i--;
            j--;
        }
        return ans1==ans2;
    }
};