class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size()-1;
        int ans;
        while(start<end) {
            int mid = start+(end-start)/2;
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]) {
                ans = mid;
            }
            if(arr[mid]<arr[mid+1]) {
                start = mid+1;
            }
            else {
                end = mid;
            }
        }
        return ans;
    }
};