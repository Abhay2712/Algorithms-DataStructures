class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>& a, vector<int>& b){
            return a[1]>b[1];
        });
        int val=0;
        for(int i=0;i<boxTypes.size();i++){
            if(boxTypes[i][0]<=truckSize){
                truckSize-=boxTypes[i][0];
                val+=boxTypes[i][0]*boxTypes[i][1];
            }
            else{
                val+=boxTypes[i][1]*truckSize;
                break;
            }
        }
        return val;
        
    }
};