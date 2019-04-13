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
    int res = 0;
    void solve(TreeNode *node, TreeNode *parent) {
        if(node->left != NULL) solve(node->left, node);
        if(node->right != NULL) solve(node->right, node);
        res += abs(node->val - 1);
        if(parent != NULL) parent->val += (node->val - 1);
    }
    int distributeCoins(TreeNode* root) {
        solve(root, NULL);
        return res;
    }
};