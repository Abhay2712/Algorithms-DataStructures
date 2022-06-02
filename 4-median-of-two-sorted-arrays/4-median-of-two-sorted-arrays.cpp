class Solution {
public:
    double findMedianSortedArrays(vector<int>&num1, vector<int>&num2) {
        int m=num1.size(),n=num2.size();
        if(m>n) return findMedianSortedArrays(num2,num1);
        
        int low=0,high=m,medianPos=((m+n)+1)/2;
        while(low<=high) {
            int cut1 = (low+high)>>1;
            int cut2 = medianPos - cut1;

            int l1 = (cut1 == 0)? INT_MIN:num1[cut1-1];
            int l2 = (cut2 == 0)? INT_MIN:num2[cut2-1];
            int r1 = (cut1 == m)? INT_MAX:num1[cut1];
            int r2 = (cut2 == n)? INT_MAX:num2[cut2];

            if(l1<=r2 && l2<=r1) {
                if((m+n)%2 != 0)
                    return max(l1,l2);
                else 
                    return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2) high = cut1-1;
            else low = cut1+1;
        }
        return 0.0;
    }
};