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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)return head;
        ListNode* root=new ListNode();
        root->next=head;

        ListNode* lastEnd=root;
        ListNode* nowHead=head;
        ListNode* now=head;
        int cnt=1;
        while(now!=nullptr) {
            if(cnt%k==0) {
                lastEnd->next=now;
                backWork(nowHead, now, now->next);
                now=nowHead->next;
                lastEnd=nowHead;
                nowHead=now;
                cnt++;
            }else {
                now=now->next;
                cnt++;
            }
        }
        return root->next;
    }
    void backWork(ListNode* now, ListNode* tail, ListNode* last) {
        if(now!=tail)
            backWork(now->next, tail, now);
        now->next=last;
    }
};