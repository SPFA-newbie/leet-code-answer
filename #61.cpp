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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return nullptr;
        ListNode* pos=head;
        int len=1;
        while(pos->next!=nullptr) pos=pos->next, len++;
        pos->next=head;
        k%=len;
        k=len-k;
        for(int i=0;i<k;i++)
            pos=pos->next, head=head->next;
        pos->next=nullptr;
        return head;
    }
};
