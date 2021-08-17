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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int maxv=root->val;
        int ans=1;
        int lev=0;
        while(!que.empty()) {
            lev++;
            int level=que.size();
            int sum=0;
            for(int i=0;i<level;++i) {
                TreeNode* now=que.front();  que.pop();
                sum+=now->val;
                if(now->left!=nullptr) {
                    que.push(now->left);
                }
                if(now->right!=nullptr) {
                    que.push(now->right);
                }
            }
            if(sum>maxv) {
                maxv=sum;
                ans=lev;
            }
        }
        return ans;
    }
};
