// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        int s1=0,s2=0,s3=0;
        string a="";
        int n=x.size();
        int count=0;
        for(auto i:x){
            if(i=='{') s1+=1;
            else if(i=='}') s1-=1;
            else if(i=='[') s2+=1;
            else if(i==']') s2-=1;
            else if(i=='(') s3+=1;
            else s3-=1;
            if(count!=n-1) a=x.substr(count,2);
            count++;
            if(a=="[)" ||a=="[}" ||a=="{)") return false;
            else if(s1<0 || s2<0 || s3<0)
                return false;
        }
        if(s1==0 && s2==0 && s3==0){
                return true;
        }
        else return false;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends