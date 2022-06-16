class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c=0,r=0,o=0,a=0,k=0;
        int count=0,res=0;
        for(auto i:croakOfFrogs){
            if(i=='c'){
                if(c<r) return -1;
                count++;
                c++;
            }
            else if(i=='r'){
                if(r<o) return -1;
                r++;
            }
            else if(i=='o'){
                if(o<a) return -1;
                o++;
            }
            else if(i=='a'){
                if(a<k) return -1;
                a++;
            }
            else{
                count--;
                k++;
            }
            res=max(res,count);
        }
        if(c==r && r==o && o==a && a==k){
            return res;
        }
        else return -1;
    }
};