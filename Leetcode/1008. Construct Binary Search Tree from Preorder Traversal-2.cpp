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
        return bst(preorder, 0, preorder.size());
    }
    
    TreeNode* bst(vector<int>& preorder, int l, int r) {
        if(l>=r) {
            return nullptr;
        }
        auto mid=upper_bound(preorder.begin()+l, preorder.begin()+r, preorder[l])-preorder.begin();
        return new TreeNode(preorder[l], bst(preorder, l+1, mid), bst(preorder, mid, r));
    }
};
