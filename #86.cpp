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
    ListNode* partition(ListNode* head, int x) {
        ListNode* GL=new ListNode();
        ListNode* LL=new ListNode();
        ListNode* p=head;
        ListNode* gp=GL;
        ListNode* lp=LL;
        while(p!=nullptr) {
            if(p->val<x) {
                lp->next=new ListNode(p->val);
                lp=lp->next;
            } else {
                gp->next=new ListNode(p->val);
                gp=gp->next;
            }
            p=p->next;
        }
        lp->next=GL->next;
        return LL->next;
    }
};
