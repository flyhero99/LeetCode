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
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return NULL;
        if(root->left) root->left = pruneTree(root->left);
        if(root->right) root->right = pruneTree(root->right);
        if(!root->val && !root->left && !root->right) return NULL;
        return root;
    }
};