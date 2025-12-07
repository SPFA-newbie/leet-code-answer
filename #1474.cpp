/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* last = head;
        ListNode* now = head->next;
        int pos = 1;
        while (now != nullptr) {
            if (pos % (m + n) < m) {
                last = now;
                now = now->next;
            } else {
                last->next = now->next;
                now = now->next;
            }
            pos++;
        }
        return head;
    }
};