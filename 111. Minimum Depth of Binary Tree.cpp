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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return get(root);
        // if(root->left == NULL && root->right == NULL) return 1;
        // return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
    
    int get(TreeNode* root) {
        if(root == NULL) return 999999;
        if(root->left == NULL && root->right == NULL) return 1;
        return min(get(root->left), get(root->right)) + 1;
    }
};