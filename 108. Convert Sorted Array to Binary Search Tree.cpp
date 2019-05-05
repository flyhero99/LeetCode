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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        int mid = nums.size()/2;
        TreeNode *node = new TreeNode(nums[mid]);
        auto lson = vector<int>(nums.begin(), nums.begin()+mid);
        auto rson = vector<int>(nums.begin()+mid+1, nums.end());
        if(mid != 0) node->left = sortedArrayToBST(lson);
        if(mid != nums.size()-1) node->right = sortedArrayToBST(rson);
        return node;
    }
};