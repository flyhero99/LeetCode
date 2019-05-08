/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return new TreeNode(head->val);
        ListNode *s = head, *f = head->next->next;
        while(f != NULL && f->next != NULL) {
            s = s->next;
            f = f->next->next;
        }
        ListNode *l = head, *m = s->next, *r = m->next;
        s->next = NULL;
        TreeNode *root = new TreeNode(m->val);
        root->left = sortedListToBST(l);
        root->right = sortedListToBST(r);
        return root;
    }
};