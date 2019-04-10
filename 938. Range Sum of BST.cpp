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
    int rangeSumBST(TreeNode* root, int L, int R) {
        vector<int> vec;
        inOrder(root, vec);
        int l = lower_bound(vec.begin(), vec.end(), L) - vec.begin();
        int r = lower_bound(vec.begin(), vec.end(), R) - vec.begin();
        int sum = 0;
        for(int i = l+1; i < r; i++) sum += vec[i];
        if(vec[l] == L) sum += vec[l];
        if(vec[r] == R) sum += vec[r];
        // for(int i = 0; i < vec.size(); i++) cout << vec[i] << ' '; cout << endl;
        return sum;
    }
    
    void inOrder(TreeNode* root, vector<int> &vec) {
        if(root == NULL) return;
        if(root->left != NULL)
            inOrder(root->left, vec);
        vec.push_back(root->val);
        if(root->right != NULL)
            inOrder(root->right, vec);
    }
};