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
        if(root1==nullptr || root2==nullptr) {
            return false;
        }
        int sum=root1->val+root2->val;
        if(sum==target) {
            return true;
        } else if(sum<target) {
            return twoSumBSTs(root1->right, root2, target) || twoSumBSTs(root1, root2->right, target); 
        } else {
            return twoSumBSTs(root1->left, root2, target) || twoSumBSTs(root1, root2->left, target); 
        }
    }
    
    
};
