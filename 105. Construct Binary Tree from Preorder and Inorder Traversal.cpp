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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    
    TreeNode* solve(vector<int>& pre, int l1, int r1, vector<int>& in, int l2, int r2) {
        TreeNode *root = NULL;
        if(l1 > r1) return NULL;
        if(l1 == r1) return new TreeNode(pre[l1]);
        root = new TreeNode(pre[l1]);
        int i;
        for(i = l2; i < r2; i++)
            if(in[i] == pre[l1]) break;
        int index = i - l2;
        root->left = solve(pre, l1+1, l1+index, in, l2, l2+index-1);
        root->right = solve(pre, l1+index+1, r1, in, l2+index+1, r2);
        return root;
    }
};