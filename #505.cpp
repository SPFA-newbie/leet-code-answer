#include<vector>
#include<map>
#include<queue>
using namespace std;

typedef pair<int, int> Pos;
struct V {
    int lL, rL, uL, dL;
    Pos l, r, u, d;
    int dis;
    char from;
    bool arr;
    V() {
        lL = rL = uL = dL = 0;
        l = r = u = d = make_pair(-1, -1);
        dis = from = 0;
        arr = false;
    }
};
map<Pos, V> g;
struct cmp {
    bool operator()(pair<Pos, int> a, pair<Pos, int> b) {
        return a.second > b.second;
    }
};

class Solution {
public:
    void CreateEdge(int x, int y, int xx, int yy) {
        Pos p1 = make_pair(x, y);
        Pos p2 = make_pair(xx, yy);
        if (g.find(p1) == g.end()) g.insert(make_pair(p1, V()));
        if (g.find(p2) == g.end()) g.insert(make_pair(p2, V()));
        if (x > xx) {
            g[p1].l = p2;
            g[p1].lL = x - xx;
        } else if (xx > x) {
            g[p1].r = p2;
            g[p1].rL = xx - x;
        } else if (y > yy) {
            g[p1].d = p2;
            g[p1].dL = y - yy;
        } else if (yy > y) {
            g[p1].u = p2;
            g[p1].uL = yy - y;
        }
    }
    void DFS(vector<vector<int>>& maze, int x, int y, int lastX, int lastY) {
        if (lastX != -1) {
            CreateEdge(lastX, lastY, x, y);
        }
        if (maze[x][y] == 2) return;
        maze[x][y] = 2;
        if (x > 0 && maze[x-1][y] != 1) {
            int newP = x - 1;
            while (newP >= 0 && maze[newP][y] != 1) newP--;
            newP++;
            DFS(maze, newP, y, x, y);
        }
        if (y > 0 && maze[x][y-1] != 1) {
            int newP = y - 1;
            while (newP >= 0 && maze[x][newP] != 1) newP--;
            newP++;
            DFS(maze, x, newP, x, y);
        }
        if (x < maze.size() - 1 && maze[x+1][y] != 1) {
            int newP = x + 1;
            while (newP < maze.size() && maze[newP][y] != 1) newP++;
            newP--;
            DFS(maze, newP, y, x, y);
        }
        if (y < maze[x].size() - 1 && maze[x][y+1] != 1) {
            int newP = y + 1;
            while (newP < maze[x].size() && maze[x][newP] != 1) newP++;
            newP--;
            DFS(maze, x, newP, x, y);
        }
    }
    void Dij(Pos start) {
        priority_queue<pair<Pos, int>, vector<pair<Pos, int>>, cmp> heap;
        Pos stop = make_pair(-1, -1);
        heap.push(make_pair(start, 0));
        while (!heap.empty()) {
            Pos pos = heap.top().first;
            int dis = heap.top().second;
            heap.pop();
            auto it = g.find(pos);
            if (it->second.arr) continue;
            it->second.dis = dis;
            it->second.arr = true;
            if (it->second.l != stop && !g[it->second.l].arr)
                heap.push(make_pair(it->second.l, it->second.lL + dis));
            if (it->second.r != stop && !g[it->second.r].arr)
                heap.push(make_pair(it->second.r, it->second.rL + dis));
            if (it->second.d != stop && !g[it->second.d].arr)
                heap.push(make_pair(it->second.d, it->second.dL + dis));
            if (it->second.u != stop && !g[it->second.u].arr)
                heap.push(make_pair(it->second.u, it->second.uL + dis));
        }
    }
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        g.clear();
        Pos beg = make_pair(start[0], start[1]);
        Pos tar = make_pair(destination[0], destination[1]);
        if (beg == tar) return 0;
        DFS(maze, start[0], start[1], -1, -1);
        Dij(beg);
        if (g[tar].dis == 0) return -1;
        return g[tar].dis;
    }
};