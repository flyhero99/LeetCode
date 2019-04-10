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
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = NULL;
        for(int i = 0; i < preorder.size(); i++) {
            add(root, preorder[i]);
        }
        return root;
    }
    
    void add(TreeNode* &root, int val) {
        if(root == NULL) {
            root = (TreeNode*)malloc(sizeof(TreeNode));
            root->val = val;
            root->left = root->right = NULL;
            return;
        }
        if(val > root->val) add(root->right, val);
        else add(root->left, val);
    }
};