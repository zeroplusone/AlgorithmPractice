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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0) {
            return nullptr;
        }
        auto mid=upper_bound(preorder.begin(), preorder.end(), preorder[0]);
        vector<int> left(preorder.begin()+1, mid);
        vector<int> right(mid, preorder.end());
        return new TreeNode(preorder[0], bstFromPreorder(left), bstFromPreorder(right));
    }
};
