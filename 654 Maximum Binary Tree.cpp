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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        else if(nums.size() == 1) {
            TreeNode *root = new TreeNode(nums[0]);
            return root;
        }
        else {
            int maxx = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] > nums[maxx]) maxx = i;
            }
            vector<int> ll, rr;
            for(int i = 0; i < maxx; i++)
                ll.push_back(nums[i]);
            for(int i = maxx+1; i < nums.size(); i++)
                rr.push_back(nums[i]);
            TreeNode *root = new TreeNode(nums[maxx]);
            root->left = constructMaximumBinaryTree(ll);
            root->right = constructMaximumBinaryTree(rr);
            return root;
        }
    }
};