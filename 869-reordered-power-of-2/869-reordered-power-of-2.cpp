class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string str = sort_num(N);
        
        for (int i = 0; i < 32; i++)
            if (str == sort_num(1 << i)) return true;
        return false;
    }
    
    string sort_num(int n) {
        string res = to_string(n);
        sort(res.begin(), res.end());
        return res;
    }
};