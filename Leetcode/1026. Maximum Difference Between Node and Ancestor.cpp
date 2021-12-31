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
    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        DFS(root, root->val, root->val, ans);
        return ans;
    }
    
    void DFS(TreeNode* root, int minv, int maxv, int& ans) {
        if(root==nullptr) {
            return;
        }
        ans=max(ans, abs(minv-root->val));
        ans=max(ans, abs(maxv-root->val));
        
        minv=min(minv, root->val);
        maxv=max(maxv, root->val);
        DFS(root->left, minv, maxv, ans);
        DFS(root->right, minv, maxv, ans);
    }
};
