/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, TreeNode* &pre, vector<TreeNode*> &res) {
        if(root == NULL) return;
        solve(root->left, pre, res);
        if(pre != NULL && pre->val > root->val) {
            res.push_back(pre);
            res.push_back(root);
        }
        pre = root;
        solve(root->right, pre, res);
    }
    
    void recoverTree(TreeNode* root) {
        if(root == NULL) return;
        vector<TreeNode*> res;
        TreeNode* pre = NULL;
        solve(root, pre, res);
        if(res.size() > 0) {
            if(res.size() == 2) swap(res[0]->val, res[1]->val);
            if(res.size() == 3) swap(res[0]->val, res[2]->val);
            if(res.size() == 4) swap(res[0]->val, res[3]->val);
        }
    }
};