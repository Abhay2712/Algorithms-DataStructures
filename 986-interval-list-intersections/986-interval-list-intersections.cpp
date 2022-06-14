class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0,j=0;
        int n=firstList.size(),m=secondList.size();
        int start,end;
        vector<vector<int>>res;
        while(i<n && j<m){
            start=max(firstList[i][0],secondList[j][0]);
            end=min(firstList[i][1],secondList[j][1]);
            
            if(start<=end) res.push_back({start,end});
            if(firstList[i][1]>secondList[j][1]) j++;
            else i++;
            }
        return res;
    }
};