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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ans(0);
        index = 0;
        return solve(root, voyage, ans)?ans:vector<int>{-1};
    }
    
    int index;
    
    bool solve(TreeNode* root, vector<int>& voyage, vector<int>& ans) {
        if(!root) {
            return true;
        }
        
        if(root->val != voyage[index]) {
            return false;
        }
        index++;
        if(root->left && root->left->val!=voyage[index]) {
            ans.push_back(root->val);
            return solve(root->right, voyage, ans) && solve(root->left, voyage, ans);
        } else {
            return solve(root->left, voyage, ans) && solve(root->right, voyage, ans);
        }
    }
    
};
