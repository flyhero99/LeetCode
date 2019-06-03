/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int up = 0;
        ListNode *root = NULL, *cur = NULL, *s = NULL;
        while(l1!=NULL || l2!=NULL || up) {
            int x;
            if(l1 == NULL && l2 == NULL) {
                x = up;
                up = 0;
            }
            else if(l1 == NULL && l2 != NULL) {
                x = up + l2->val;
                up = 0;
                if(x >= 10) { x -= 10; up = 1; }
            }
            else if(l2 == NULL && l1 != NULL) {
                x = up + l1->val;
                up = 0;
                if(x >= 10) { x -= 10; up = 1; }
            }
            else {
                x = up + l1->val + l2->val;
                up = 0;
                if(x >= 10) { x -= 10; up = 1; }
            }
            s = new ListNode(x);
            if(root == NULL) root = s;
            else cur->next = s;
            cur = s;
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }
        return root;
    }
};