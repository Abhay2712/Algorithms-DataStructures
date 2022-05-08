class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList); 
    }
    void dfs(vector<NestedInteger> &nestedList) {
         for(int i=nestedList.size()-1;i>=0;i--)
            if(nestedList[i].isInteger()) stk.push(nestedList[i].getInteger());
            else dfs(nestedList[i].getList());
    }
    int next() {
        int nxt = stk.top();
        stk.pop();
        return nxt;
    }
    bool hasNext() {
        return !stk.empty();
    }
private:
    stack<int> stk;
};