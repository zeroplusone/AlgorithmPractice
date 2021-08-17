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
    int goodNodes(TreeNode* root) {
        int ans=0;
        DFS(root, -1e9, ans);
        return ans;
    }
    
    void DFS(TreeNode* root, int maxv, int& ans) {
        if(root==nullptr) {
            return;
        }
        if(root->val>=maxv) {
            ans++;
        }

        DFS(root->left, max(maxv, root->val), ans);
        DFS(root->right, max(maxv, root->val), ans);
    }
};
