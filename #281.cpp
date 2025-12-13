#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
using namespace std;

class ZigzagIterator {
public:
    vector<int> a[2];
    int pos[2], to;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        a[0] = v1;
        a[1] = v2;
        pos[0] = pos[1] = 0;
        to = 0;
    }

    int next() {
        if (pos[to] == a[to].size()) {
            to++;
            to %= 2;
        }
        int ans = a[to][pos[to]];
        pos[to]++;
        to++;
        to %= 2;
        return ans;
    }

    bool hasNext() {
        return !(pos[0] == a[0].size() && pos[1] == a[1].size());
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */