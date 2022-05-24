class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> p;
        int maxlength=0;
        p.push(-1);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                p.push(i);
            }
            else{
                p.pop();
                if(p.empty())
                    p.push(i);
                else
                    maxlength=max(maxlength,i-p.top());
            }
        }
        return maxlength;
    }
};