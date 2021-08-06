/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==nullptr) {
            return vector<vector<int>>(0);
        }
        
        vector<vector<int>> ans(0);
        queue<Node*> que;
        que.push(root);
        
        Node* now;
        while(!que.empty()) {
            int n=que.size();
            vector<int> level;
            for(int i=0;i<n;++i) {
                now=que.front();
                que.pop();
                level.push_back(now->val);
                for(int j=0;j<now->children.size();++j){
                    que.push(now->children[j]);    
                }
            }
            ans.push_back(level);
        }
        return ans;
        
        
    }
};
