class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) 
    {
        int n = encoded.size() + 1;
        vector <int> decoded(n);
        decoded[0] = first;
        for(int i = 1; i < n; i++)
            decoded[i] = encoded[i-1]^decoded[i-1];
        return decoded;
    }
};