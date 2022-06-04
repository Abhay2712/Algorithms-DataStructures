class Solution {
public:
    int reverse(int x) {
        long int ans = 0;
        while(x) {
            ans = (ans * 10) + (x % 10); 
            x /= 10; 
            }
        return (ans > INT_MAX or ans < INT_MIN) ? 0 : ans;
    }
};