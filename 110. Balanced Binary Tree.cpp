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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        return getDepth(root) != -1;
    }
    
    int getDepth(TreeNode *root) {
        if(root == NULL) return 0;
        int ldep = getDepth(root->left);
        int rdep = getDepth(root->right);
        if(ldep == -1 || rdep == -1 || abs(ldep-rdep) > 1) return -1;
        else if(ldep > rdep) return ldep+1;
        else return rdep+1;
    }
};