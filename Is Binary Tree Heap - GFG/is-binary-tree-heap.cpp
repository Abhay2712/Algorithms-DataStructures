// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    unsigned int countNodes(struct Node* root)
    {
        if (root == NULL)
            return (0);
        return (1 + countNodes(root->left) + countNodes(root->right));
    }
  
    bool isCompleteUtil (struct Node* root,unsigned int index,unsigned int number_nodes)
    {
        if (root == NULL) return (true);
     
        if (index >= number_nodes)
            return (false);
     
        return (isCompleteUtil(root->left, 2*index + 1,number_nodes) && 
        isCompleteUtil(root->right, 2*index + 2, number_nodes));
    }
    
    bool isHeapUtil(struct Node* root)
    {
        if (root->left == NULL && root->right == NULL)
            return (true);
     

        if (root->right == NULL)
        {
            return (root->data >= root->left->data);
        }
        else
        {
            if (root->data >= root->left->data && root->data >= root->right->data)
                return ((isHeapUtil(root->left)) && (isHeapUtil(root->right)));
            else
                return (false);
        }
    }
    
    bool isHeap(struct Node* root) {
        unsigned int node_count = countNodes(root);
        unsigned int index = 0;
     
        if (isCompleteUtil(root, index,node_count) && isHeapUtil(root))
            return true;
        return false;
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}  // } Driver Code Ends