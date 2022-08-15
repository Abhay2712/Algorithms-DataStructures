class Solution {
public:
     int romanToInt(string s)

    {
        int n=s.size();
        int hash[256]={0};
        hash['I']=1;
        hash['V']=5;
        hash['X']=10;
        hash['L']=50;   
        hash['C']=100;
        hash['D']=500;
        hash['M']=1000;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(hash[s[i]]>=hash[s[i+1]]){
                ans+=hash[s[i]];
            }

            else{ 
                ans-=hash[s[i]];

            }
        }
        return ans;
    }
};