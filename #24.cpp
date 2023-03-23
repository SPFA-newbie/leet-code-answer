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
    ListNode* swapPairs(ListNode* head) {
        ListNode* root=new ListNode();
        root->next=head;
        ListNode* father=root;
        ListNode* now=head;
        while(now!=nullptr && now->next!=nullptr) {
            father->next=now->next;
            father=now;
            now=now->next->next;
            father->next->next=father;
            father->next=nullptr;
        }
        if(now!=nullptr && now->next==nullptr)
            father->next=now;
        return root->next;
    }
};