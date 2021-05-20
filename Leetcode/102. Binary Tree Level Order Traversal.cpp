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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans(0);
        
        if(root!=nullptr) {
            queue<TreeNode*> que;
            que.push(root);
            while(!que.empty()) {
                int n=que.size();
                vector<int> level(n);
                for(int i=0;i<n;++i) {
                    TreeNode* now = que.front();
                    level[i]=now->val;
                    if(now->left!=nullptr) {
                        que.push(now->left);
                    } 
                    if(now->right!=nullptr) {
                        que.push(now->right);
                    }
                    que.pop();
                }
                ans.push_back(level);
            }
        }
        return ans;
    }
};
