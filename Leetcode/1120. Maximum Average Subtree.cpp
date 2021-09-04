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
    double maximumAverageSubtree(TreeNode* root) {
        double ans=0;
        traverse(root, ans);
        return ans;
    }
    
    // total, node num
    pair<int, int> traverse(TreeNode* root, double& ans) {
        if(root==nullptr) {
            return make_pair(0, 0);
        }
        
        pair<int, int> l=traverse(root->left, ans);
        pair<int, int> r=traverse(root->right, ans);
        
        int total=l.first+r.first+root->val;
        double num=l.second+r.second+1;
        ans=max(ans, total/num);
        return make_pair(total, num);
    }
};
