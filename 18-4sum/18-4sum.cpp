class Solution {
public:
   vector<vector<int>> fourSum(vector<int>& num, int target) {
        vector<vector<int> > res;
        int n = num.size(); 
        if (n<4)
            return res;
        
        sort(num.begin(),num.end());
        for (int i = 0; i < n; i++) {
            int target_3 = target - num[i];
            for (int j = i + 1; j < n; j++) {
                int target_2 = target_3- num[j];
            
                int front = j + 1;
                int back = n - 1;
                while(front < back) {
                
                    int two_sum = num[front] + num[back];
                    if (two_sum < target_2) front++;
                
                    else if (two_sum > target_2) back--;
                
                    else {
                        res.push_back({num[i],num[j],num[front],num[back]});
                        int f=num[front];
                        int b=num[back];
                    
                        // Processing the duplicates of number 3
                        while (front < back && num[front] == f) ++front;
                    
                        // Processing the duplicates of number 4
                        while (front < back && num[back] == b) --back;
                
                    }
                }
                
                // Processing the duplicates of number 2
                while(j + 1 < n && num[j + 1] == num[j]) ++j;
            }
        
            // Processing the duplicates of number 1
            while (i + 1 < n && num[i + 1] == num[i]) ++i;
        
        }
    
        return res;
    }
};