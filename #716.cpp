#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_set>
using namespace std;

struct Ele {
    int id;
    int val;
    Ele(int _id, int _val) {
        id = _id;
        val = _val;
    }
};

struct StackCmp {
    bool operator()(const Ele& a, const Ele& b) {
        return a.id < b.id;
    }
};

struct MaxCmp {
    bool operator()(const Ele& a, const Ele& b) {
        return a.val == b.val ? a.id < b.id : a.val < b.val;
    }
};

class MaxStack {
public:
    priority_queue<Ele, vector<Ele>, StackCmp> s;
    priority_queue<Ele, vector<Ele>, MaxCmp> max_s;
    unordered_set<int> del_s;
    int count;
    MaxStack() {
        s = priority_queue<Ele, vector<Ele>, StackCmp>();
        max_s = priority_queue<Ele, vector<Ele>, MaxCmp>();
        del_s.clear();
        count = 0;
    }
    
    void push(int x) {
        s.push(Ele(count, x));
        max_s.push(Ele(count, x));
        count++;
    }
    
    int pop() {
        Ele e = s.top();
        while (del_s.find(e.id) != del_s.end()) {
            s.pop();
            e = s.top();
        }
        s.pop();
        del_s.insert(e.id);
        return e.val;
    }
    
    int top() {
        Ele e = s.top();
        while (del_s.find(e.id) != del_s.end()) {
            s.pop();
            e = s.top();
        }
        return e.val;
    }
    
    int peekMax() {
        Ele e = max_s.top();
        while (del_s.find(e.id) != del_s.end()) {
            max_s.pop();
            e = max_s.top();
        }
        return e.val;
    }
    
    int popMax() {
        Ele e = max_s.top();
        while (del_s.find(e.id) != del_s.end()) {
            max_s.pop();
            e = max_s.top();
        }
        max_s.pop();
        del_s.insert(e.id);
        return e.val;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */