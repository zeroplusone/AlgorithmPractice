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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans(0);
        vector<int> path(0);
        DFS(root, 0, targetSum, ans, path);
        return ans;
    }
    
    void DFS(TreeNode* root, int sum, int& targetSum, vector<vector<int>>& ans, vector<int>& path) {
        if(root==nullptr) {
            return;
        }
        path.push_back(root->val);
        sum+=root->val;
        if(root->left==nullptr && root->right==nullptr) {
            if(sum==targetSum) {
                ans.push_back(path);
            }
            path.pop_back();
            return;
        }
        

        DFS(root->left, sum, targetSum, ans, path);
        DFS(root->right, sum, targetSum, ans, path);  

        path.pop_back();
        return;
    }
    
};
