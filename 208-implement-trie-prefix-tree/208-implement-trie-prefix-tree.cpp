class Trie {
public:
    struct Node{
        Node *links[26];
        bool flag=0;
        bool containsKey(char ch){
            return links[ch-'a']!=NULL;
        }
        void put(char ch,Node *node){
            links[ch-'a']=node;
        }
        
        Node *get(char ch){
            return links[ch-'a'];
        }
    };
    
    Node *root;
    
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node *node=root;
        for(char i:word){
            if(!node->containsKey(i)){
                node->put(i,new Node());
            }
            node=node->get(i);
        }
        node->flag=1;
    }
    
    bool search(string word) {
        Node *node=root;
        for(char i:word){
            if(!node->containsKey(i)){
                return 0;
            }
            else node=node->get(i);
            
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node *node=root;
        for(auto i:prefix){
            if(!node->containsKey(i)) return 0;
            node=node->get(i);
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */