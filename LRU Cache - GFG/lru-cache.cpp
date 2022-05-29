// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
    
    int size = 0;
    list<pair<int, int>> dq;
    unordered_map<int, list<pair<int, int>>::iterator> ump;
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        size = cap;
        ump.clear();
        dq.clear();
    }
    
    // dq front consists of the LRU
    
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(ump.find(key) == ump.end()) return -1;
        
        auto it = ump[key];
        int val = it->second;
        dq.erase(it);
        dq.push_back({key, val});
        
        // point to the last of the list
        it = dq.end();
        it--;
        
        ump[key] = it;
        
        return val;
        
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if(ump.find(key) != ump.end()){
            auto it = ump[key];
            dq.erase(it);
        } 
        else if(ump.size() == size){
            int x = dq.front().first; //  key
            ump.erase(x);
            dq.pop_front(); //  removes the LRU
        }
        dq.push_back({key, value});
        auto it = dq.end();
        it--;
        ump[key] = it;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends