class Solution {
public:
    static bool compare(string &s1,string &s2)
    {
        return s1.size()>s2.size();
    }
    
    int maxProduct(vector<string>& words) {
        
    sort(words.begin(),words.end(),compare);
	int n = size(words), ans = 0;
	vector<bitset<26> > chars(n);
	for(int i = 0; i < n; i++) {
		for(auto ch : words[i])  // map the letters to 1 if it occurs in the word
			chars[i][ch - 'a'] = 1;

		for(int j = 0; j < i; j++)
			if(!checkCommon(chars[i], chars[j])) 
				ans = max(ans, int(size(words[i]) * size(words[j])));
	}   
	return ans;
}

    bool checkCommon(bitset<26>& a, bitset<26>& b) {
        for(int i = 0; i < 26; i++) if (a[i] && b[i]) return true;
        return false;
    }
};