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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        vector<int> temp;
        if(root == NULL) return res;
        int cur = 0;
        dfs(root, sum, cur, temp, res);
        return res;
    }
    
    void dfs(TreeNode* root, int sum, int cur, vector<int> &temp, vector<vector<int> > &res) {
        if(root == NULL) return;
        cur += root->val;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            if(sum == cur) res.push_back(temp);
            temp.pop_back();
            cur -= root->val;
            return;
        }
        dfs(root->left, sum, cur, temp, res);
        dfs(root->right, sum, cur, temp, res);
        cur -= root->val;
        temp.pop_back();
        return;
    }
};