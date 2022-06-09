class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int k) {
        int n=arr.size();
        int i=0,j=n-1;
        while(i<j){
            if(arr[i]+arr[j]==k){
                return(vector<int>{i+1,j+1});       
            }
            else if(arr[i]+arr[j]>k){
                j--;
            }
            else{
                i++;
            }
        }
        return{-1,-1};
    }
};