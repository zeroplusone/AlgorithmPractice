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
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path{0};
        int ans=0;
        find(root, targetSum, path, ans);
        return ans;
    }
    
    void find(TreeNode* root, int& targetSum, vector<int>& path, int& ans) {
        if(root==nullptr) {
            return;
        }
        
        int sum=path[path.size()-1]+root->val;
        path.push_back(sum);


        for(int i=0;i<path.size()-1;++i) {
            if(sum-path[i]==targetSum) {
                ans++;
            }
        }

        find(root->left, targetSum, path, ans);
        find(root->right, targetSum, path, ans);
        path.pop_back();
    }
};
