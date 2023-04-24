/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include<map>
using namespace std;

class Solution {
public:
    map<Node*, Node*> m;
    Node* copyRandomList(Node* head) {
        Node* ret=new Node(0);
        Node* now=ret;
        while(head!=nullptr) {
            now->next=new Node(head->val);
            m.insert(pair<Node*, Node*>(head, now->next));
            now=now->next;
            now->next=nullptr;
            now->random=head->random;
            head=head->next;
        }
        now=ret->next;
        while(now!=nullptr) {
            if(now->random!=nullptr)
                now->random=m[now->random];
            now=now->next;
        }
        return ret->next;
    }
};
