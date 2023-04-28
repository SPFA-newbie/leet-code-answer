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
#include<cstdlib>
using namespace std;

class Solution {
public:
    ListNode* h;
    int len;
    Solution(ListNode* head) {
        len=0;
        h=head;
        while(head!=nullptr) {
            len++;
            head=head->next;
        }
    }
    
    int getRandom() {
        ListNode* pos=h;
        int t=len;
        while(pos!=nullptr) {
            if(rand()%t==0)   
                return pos->val;
            pos=pos->next;
            t--;
        }
        return h->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */