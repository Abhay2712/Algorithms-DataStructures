// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++
class Solution
{
    public:
    Node* addOne(Node *head) 
    {   
        if(!head->next){
            head->data+=1;
            return head;
        }
        int carry=0;
        add(head,carry,head);
        return head;
    }
    
    public:
    void add(Node *temp,int &carry,Node *head){
        if(temp->next) add(temp->next,carry,head);
        
        if(!temp->next){
            if(temp->data==9){
                temp->data=0;
                carry=1;
            }
            else{
                temp->data+=1+carry;
                carry=0;
            }
        }
        else if(temp==head){
            temp->data+=min(1,carry);
        }
        
        else{
            if(temp->data==9 && carry){
                temp->data=0;
                carry=1;
            }
            else{
                temp->data+=carry;
                carry=0;
            }
        }
    
    }
    
};
    
// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends