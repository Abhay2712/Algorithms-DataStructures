class Solution {
public:
    int maxArea(int h, int w, vector<int>& hor, vector<int>& ver) {
        sort(hor.begin(),hor.end());
        sort(ver.begin(),ver.end());
        int vmax=max(ver[0],w-ver[ver.size()-1]),hmax=max(hor[0],h-hor[hor.size()-1]);
        
        for(int i=0;i<ver.size()-1;i++){
            vmax=max(vmax,ver[i+1]-ver[i]);
        }
        
        for(int i=0;i<hor.size()-1;i++){
            hmax=max(hmax,hor[i+1]-hor[i]);
        }
        long res=(long)hmax*(long)vmax;
        long rem=1e9+7;
        return (res%rem);
    }
};