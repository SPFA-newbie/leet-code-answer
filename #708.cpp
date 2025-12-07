/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* now = head;
        Node* newNode = new Node(insertVal);
        if (head == nullptr) {
            newNode->next = newNode;
            return newNode;
        }
        bool cir = false;
        while (1) {
            if (now->next == head) {
                if (cir) {
                    newNode->next = head;
                    now->next = newNode;
                    return head;
                }
                cir = true;
            }
            if (now->val < insertVal && now->next->val >= insertVal) {
                newNode->next = now->next;
                now->next = newNode;
                return head;
            }
            if (cir && now->val > now->next->val) {
                newNode->next = now->next;
                now->next = newNode;
                return head;
            }
            now = now->next;
        }
        return head;
    }
};