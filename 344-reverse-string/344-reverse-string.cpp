class Solution {
public:
	void reverseString(vector<char>& s) {
	int left = 0;                         //1st pointer is pointing to index 0
    int right = s.size() - 1;        //2nd pointer is pointing to last index
    
    while(left < right){
	
	 /*now we are swapping value of both the pointers and incrementing left pointer by 1 and decrementing right pointer by 1*/
	
        char temp = s[left];   
        s[left++] = s[right];
        s[right--] = temp;
       
		}

	}

};