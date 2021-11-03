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
    int sumNumbers(TreeNode* root) {
        int ans=0;
        traverse(root, 0, ans);
        return ans;
    }
    
    void traverse(TreeNode* root, int sum, int& ans) {
        if(root==nullptr) {
            return;
        } 
        sum=sum*10+root->val;
        if(root->left==nullptr && root->right==nullptr) {
            ans+=sum;
            return;
        }
        
        traverse(root->right, sum, ans);
        traverse(root->left, sum, ans);
    }
};
