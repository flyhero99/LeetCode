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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    
    TreeNode* solve(vector<int>& in, int l1, int r1, vector<int>& post, int l2, int r2) {
        TreeNode *root = NULL;
        if(l2 > r2) return NULL;
        if(l2 == r2) return new TreeNode(post[r2]);
        root = new TreeNode(post[r2]);
        int i;
        for(i = l1; i < r1; i++)
            if(in[i] == post[r2]) break;
        int index = i - l1;
        root->left = solve(in, l1, l1+index-1, post, l2, l2+index-1);
        root->right = solve(in, l1+index+1, r1, post, l2+index, r2-1);
        return root;
    }
};