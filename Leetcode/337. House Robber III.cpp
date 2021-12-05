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
    int rob(TreeNode* root) {
        pair<int, int> ans=solve(root);
        return max(ans.first, ans.second);
    }
    
    // select, unselect
    pair<int, int> solve(TreeNode* root) {
        if(root==nullptr) {
            return make_pair(0, 0);
        }
        
        pair<int, int> l=solve(root->left);
        pair<int, int> r=solve(root->right);
        int select=root->val+l.second+r.second;
        int unselect=max(l.first, l.second)+max(r.first, r.second);
        return make_pair(select, unselect);
    }
};
