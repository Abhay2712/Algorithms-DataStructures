class Solution {
public:
    int climbStairs(int n) {
      int f1=1,f2=2,ans;
      for(int i=1;i<=n;i++)
      {
        if(i==1)
          ans=1;
        else if(i==2)
          ans=2;
        else
          ans=f1+f2;
          f1=f2;
          f2=ans;
      }
      return ans;      
    }
};