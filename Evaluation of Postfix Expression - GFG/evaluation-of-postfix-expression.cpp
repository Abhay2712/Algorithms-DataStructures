// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
        {
            // Your code here
            stack<int> st;
        
        int i=0;
        while(S[i]){
            
            // if current character is operator then perform operation
            if(S[i]=='*' || S[i]=='/' || S[i]=='+' || S[i]=='-'){
                int b = st.top();
                    st.pop();
                    
                int a = st.top();
                st.pop();
                
                switch(S[i]){
                    case '*':st.push(a*b); break;
                    
                    case '/':st.push(a/b); break;
                    
                    case '+':st.push(a+b); break;
                    
                    case '-':st.push(a-b); break;
                }
            }
            
            // else current char must be number. just push in stak
            else{
                st.push(S[i]-'0');
            }
            i++;
        }
        return st.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends