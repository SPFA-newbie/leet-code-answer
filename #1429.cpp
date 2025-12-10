#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<unordered_set>
using namespace std;

class FirstUnique {
public:
    queue<int> q;
    unordered_set<int> in;
    unordered_set<int> bin;
    void insert(int n) {
        q.push(n);
        if (bin.find(n) == bin.end()) {
            if (in.find(n) == in.end()) {
                in.insert(n);
            } else {
                in.erase(n);
                bin.insert(n);
            }
        }
    }
    FirstUnique(vector<int>& nums) {
         for (auto n: nums) {
            insert(n);
         }
    }
    
    int showFirstUnique() {
        while (!q.empty() && in.find(q.front()) == in.end()) {
            q.pop();
        }
        return q.empty() ? -1 : q.front();
    }
    
    void add(int value) {
        insert(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */