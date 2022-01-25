class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        if(arr.size() == 1){return arr;}
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        int p1 = 0;
        int p2 = 1;
        while(p2<arr.size()){
            if(ans[p1][1]>= arr[p2][1]){
                p2++;
            }
            else if(ans[p1][1] >= arr[p2][0]){
                ans[p1][1] = arr[p2][1];
                p2++;
            }
            else{
                ans.push_back(arr[p2]);
                p1++; p2++;
            }
        }
        return ans;
    }
};