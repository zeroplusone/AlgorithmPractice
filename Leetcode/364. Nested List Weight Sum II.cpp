/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> depth;
        int maxDepth=1;
        genDepth(nestedList, 1, maxDepth, depth);
        int ans=0;
        int index=0;
        solve(nestedList, ans, maxDepth, depth, index);
        return ans;
    }
    
    void genDepth(vector<NestedInteger>& nestedList, int now, int& maxDepth, vector<int>& depth) {
        maxDepth=max(now, maxDepth);
        for(int i=0;i<nestedList.size();++i) {
            if(nestedList[i].isInteger()) {
                depth.push_back(now);
            } else {
                genDepth(nestedList[i].getList(), now+1, maxDepth, depth);
            }
        }   
    }
    
    void solve(vector<NestedInteger>& nestedList, int& ans, int& maxDepth, vector<int>& depth, int& index) {
        for(int i=0;i<nestedList.size();++i) {
            if(nestedList[i].isInteger()) {
                ans+=(maxDepth-depth[index]+1)*nestedList[i].getInteger();
                index++;
            } else {
                solve(nestedList[i].getList(), ans, maxDepth, depth, index);
            }
        } 
    }
};
