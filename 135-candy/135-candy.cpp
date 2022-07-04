//hard question
//We can consider this problem like valley and peak problem. In each valley there should be 1 candy and for each increasing solpe in either side we need to increse candy by 1. Peaks have highest candy. If any equal rating is found then candy resets to 1 as two equal neighbours may have any number of candies. The peak should contain the higher number of candy between which is calculated from the incresing slope and which is calculated from decreasing slope. Because this will satisfy the condition that peak element is having more candies than its neighbours.

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n, i=1;
        while(i<n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            
            //For increasing slope
            int peak = 0;
            while(ratings[i] > ratings [i-1]){
                peak++;
                candy += peak;
                i++;
                if(i == n) return candy;
            }
            
            //For decreasing slope
            int valley = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                valley++;
                candy += valley;
                i++;
            }
            candy -= min(peak, valley); //Keep only the higher peak
        }
        return candy;
    }
};