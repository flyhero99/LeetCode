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
    bool isValidBST(TreeNode* root) {
        long pre = numeric_limits<long>::min();
        return valid(root, pre);
    }
    
    bool valid(TreeNode* root, long &pre) {
        if(root == NULL) return true;
        bool left = valid(root->left, pre);
        if(pre >= root->val) return false; // 这里pre是左子树根结点的val
        pre = root->val;
        return left && valid(root->right, pre);
    }
};