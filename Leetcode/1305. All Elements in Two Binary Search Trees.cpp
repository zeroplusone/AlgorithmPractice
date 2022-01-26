/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> sta1, sta2;
        pushTreeNode(sta1, root1);
        pushTreeNode(sta2, root2);
        vector<int> ans;
        while(!sta1.empty() || !sta2.empty()) {
            if(sta1.empty() || (!sta2.empty() && sta1.top()->val>sta2.top()->val)) {
                ans.push_back(sta2.top()->val);
                popTreeNode(sta2);
            } else {
                ans.push_back(sta1.top()->val);
                popTreeNode(sta1);
            } 
        }
        return ans;
    }
    
    void pushTreeNode(stack<TreeNode*>& sta, TreeNode* r) {
        while(r!=nullptr) {
            sta.push(r);
            r=r->left;
        }
    }
    
    void popTreeNode(stack<TreeNode*>& sta) {
        TreeNode* t=sta.top();
        sta.pop();
        if(t->right!=nullptr) {
            pushTreeNode(sta, t->right);
        }
    }
};
