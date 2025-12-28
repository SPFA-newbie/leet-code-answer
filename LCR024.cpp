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
    ListNode* reverse(ListNode* last, ListNode* now) {
        if (now->next == nullptr) {
            now->next = last;
            return now;
        }
        ListNode* newHead = reverse(now, now->next);
        now->next = last;
        return newHead;
    }
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        return reverse(nullptr, head);
    }
};