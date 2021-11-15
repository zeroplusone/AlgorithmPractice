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
    
    static bool comparator(Node* a, Node* b) {
        return (a->val)>(b->val);
    }

    int diameter(Node* root) {
        
        update(root);
        int ans=0;
        solve(root, ans);
        return ans;
    }
    
    void print(Node* root) {
        if(root==nullptr) {
            return;
        }
        cout<<root->val<<endl;
        for(int i=0;i<root->children.size();++i) {
            print(root->children[i]);
        }
    }
    
    int update(Node* root) {
        if(root==nullptr) {
            return 0;
        }
        
        int dia=0;
        for(int i=0;i<root->children.size();++i) {
            dia=max(dia, update(root->children[i])+1);
        }
        root->val=dia;
        return root->val;
    }
    
    void solve(Node* root, int& ans) {
        if(root==nullptr) {
            return;
        }
        
        int cn=root->children.size();
        if(cn<2) {
            ans=max(ans, root->val);
        } else {
            nth_element(root->children.begin(), root->children.begin()+2, root->children.end(), comparator);
            ans=max(ans, root->children[0]->val+root->children[1]->val+2);
        }
        
        for(int i=0;i<cn;++i) {
            solve(root->children[i], ans);
        }
    }
};
