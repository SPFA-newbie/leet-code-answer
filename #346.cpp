#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<unordered_set>
using namespace std;

class MovingAverage {
public:
    double avg;
    int size;
    queue<int> q;
    MovingAverage(int size) {
        avg = 0;
        this->size = size;
    }
    
    double next(int val) {
        q.push(val);
        if (q.size() > size) {
            avg = (avg * size - q.front() + val) / size;
            q.pop();
        } else {
            avg = (avg * (q.size() - 1) + val) / q.size();
        }
        return avg;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */