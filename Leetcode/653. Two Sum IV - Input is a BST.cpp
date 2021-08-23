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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return solve(root, s, k);    
    }
    
    bool solve(TreeNode* root, unordered_set<int>& s, int& k) {
        if(root==nullptr) {
            return false;
        }
        if(s.count(root->val)!=0) {
            return true;
        }
        s.insert(k-(root->val));
        return solve(root->left, s, k) || solve(root->right, s, k);
    }
};
