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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans(0);
        if(root==nullptr) {
            return ans;
        }
        queue<TreeNode*> que;
        que.push(root);
        bool rev=false;
        while(!que.empty()) {
            int levelSize=que.size();
            vector<int> level(levelSize);
            for(int i=0;i<levelSize;++i) {
                TreeNode* now=que.front();  que.pop();
                level[i]=now->val;
                if(now->left!=nullptr) {
                    que.push(now->left);
                }
                if(now->right!=nullptr) {
                    que.push(now->right);
                }
            }
            if(rev) {
                reverse(level.begin(), level.end());
            }
            rev=!rev;
            ans.push_back(level);
        }
        return ans;
    }
};
