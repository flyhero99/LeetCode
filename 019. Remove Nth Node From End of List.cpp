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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        int cnt = 0;
        while(p != NULL) {
            p = p->next;
            cnt++;
        }
        if(cnt == n) return head->next;
        // cout << cnt << endl;
        p = head;
        ListNode* s = p;
        for(int i = 0; i < cnt-n; i++) {
            s = p;
            p = p->next;
        }
        s->next = p->next;
        return head;
    }
};