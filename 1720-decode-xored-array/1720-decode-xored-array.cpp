class Solution {
public:
    vector<int> decode(vector<int>& A, int cur) {
        vector<int> res = {cur};
        for (int& a: A)
            res.push_back(cur ^= a);
        return res;
    }
};