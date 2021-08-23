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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> s;
        traverse(root1, s, target);
        return solve(root2, s);
    }
    
    void traverse(TreeNode* root, unordered_set<int>& s, int& target) {
        if(root==nullptr) {
            return;
        }
        s.insert(target-(root->val));
        traverse(root->left, s, target);
        traverse(root->right, s, target);
    }
    
    bool solve(TreeNode* root, unordered_set<int>& s) {
        if(root==nullptr) {
            return false;
        }
        if(s.count(root->val)!=0) {
            return true;
        }
        return solve(root->left, s) || solve(root->right, s);
    }
};
