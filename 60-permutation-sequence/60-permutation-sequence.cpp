class Solution {
public:
    string getPermutation(int n, int k) {
        string ans="";
        int fact=1;
        vector<int>numbers;
        for(int i=1;i<n;i++){
            fact=fact*i;
            numbers.push_back(i);
        }                           //calculated n-1! and an array of all the elements.
        numbers.push_back(n);
        k-=1;       //because of the zero based indexing
        while(true){
            ans=ans+to_string(numbers[k/fact]);
            numbers.erase(numbers.begin()+k/fact);
            n--;
            if(n==0){
                break;
            }
            k=k%fact;
            fact=fact/n;
        }
        return ans;
    }
};