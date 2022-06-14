class Solution {
public:
    int findPeakElement(vector<int>& num) {
        int low = 0;
        int high = num.size()-1;
        
        while(low < high)
        {
            int mid = (low+high)/2;
            if(num[mid] < num[mid+1])
                low = mid+1;
            else
                high = mid;
        }
        return low;
    }
};