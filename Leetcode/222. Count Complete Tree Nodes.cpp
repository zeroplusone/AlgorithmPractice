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
    int countNodes(TreeNode* root) {
        if(root==nullptr) {
            return 0;
        } else if(root->left==nullptr) {
            return 1;
        }
        int h=0;
        TreeNode* now = root->left;
        while(now!=nullptr) {
            now=now->left;
            h++;
        }
        
        int ans=pow(2, h)-1;

        int l=0, r=pow(2, h)-1;
        int mid;
        while(l<r) {
            mid=(l+r+1)>>1;
            if(canbe(h-1, mid, root)) {
                l=mid;
            } else {
                r=mid-1;
            }
        }
        ans+=r+1;
        return ans;
    }
    
    bool canbe(int n, int path, TreeNode* root) {
        TreeNode* now=root;
        int bit=1;
        for(int i=n;i>=0;--i) {
            if(path&(1<<i)) {
                now=now->right;    
            } else {
                now=now->left;
            }
        }
        return now!=nullptr;
    }
};
