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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> que;
        
        que.push(root);
        int ans=0;
        while(!que.empty()) {
            int n = que.size();
            ans=0;
            for(int i=0;i<n;++i) {
                TreeNode* now = que.front(); que.pop();
                if(now->left==nullptr && now->right==nullptr) {
                    ans+=now->val;
                } else {
                    if(now->left!=nullptr) {
                        que.push(now->left);
                    }
                    if(now->right!=nullptr) {
                        que.push(now->right);
                    }
                }
            }
        }
        return ans;
    }
};
