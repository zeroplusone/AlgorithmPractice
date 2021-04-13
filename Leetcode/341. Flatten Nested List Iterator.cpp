/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        size=nestedList.size();
        this->nestedList=nestedList;
        nit = nullptr;

        it=0;  
        find_next_it();
    }
    
    void find_next_it() {
        while(it<size) {
            if(nestedList[it].isInteger()) {
                break;
            } else {
                if(nit==nullptr) {
                    nit = new NestedIterator(nestedList[it].getList());
                } 
                if(!nit->hasNext()) {
                    it++;
                    nit=nullptr;
                } else {
                    break;
                }
            }

        } 
        
    }
    
    int next() {
        int ret;
        if(nestedList[it].isInteger()) {
            ret = nestedList[it].getInteger();
            it++;
        } else {
            ret = nit->next();
        }
        find_next_it();
            
        return ret;
    }
    
    bool hasNext() {
        return it<size;
    }
private:
    int it;
    int size;
    NestedIterator *nit;
    vector<NestedInteger> nestedList;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
