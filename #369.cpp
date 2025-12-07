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
    bool DFS(ListNode* pos) {
        if (pos->next == nullptr) {
            pos->val++;
            if (pos->val == 10) {
                pos->val = 0;
                return true;
            }
            return false;
        }
        if (DFS(pos->next)) {
            pos->val++;
            if (pos->val == 10) {
                pos->val = 0;
                return true;
            }
        }
        return false;
    }
    ListNode* plusOne(ListNode* head) {
        if (DFS(head)) {
            ListNode* newNode = new ListNode(1, head);
            return newNode;
        }
        return head;
    }
};