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
    vector<int> postorder(Node* root) {
        if(root==nullptr) {
            return vector<int>(0);
        }
        
        vector<int> ans;
        stack<Node*> que;
        que.push(root);
        Node* now;
        while(!que.empty()) {
            now=que.top();    
            que.pop();
            ans.push_back(now->val);
            for(int i=0;i<now->children.size();++i) {
                que.push(now->children[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
