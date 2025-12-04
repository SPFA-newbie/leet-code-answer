#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<string>
using namespace std;

typedef pair<int, int> Pos;
struct V {
    int lL, rL, uL, dL;
    Pos l, r, u, d;
    int dis;
    bool arr;
    string fromDir;
    V() {
        lL = rL = uL = dL = 0;
        l = r = u = d = make_pair(-1, -1);
        dis = 0;
        arr = false;
        fromDir = "";
    }
};
struct SV {
    int dis;
    string dir;
    SV(int d, string s) {
        dis = d;
        dir = s;
    }
};
map<Pos, V> g;
struct cmp {
    bool operator()(pair<Pos, SV> a, pair<Pos, SV> b) {
        return a.second.dis != b.second.dis ?
                    a.second.dis > b.second.dis :
                    a.second.dir > b.second.dir;
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
            g[p1].u = p2;
            g[p1].uL = x - xx;
        } else if (xx > x) {
            g[p1].d = p2;
            g[p1].dL = xx - x;
        } else if (y > yy) {
            g[p1].l = p2;
            g[p1].lL = y - yy;
        } else if (yy > y) {
            g[p1].r = p2;
            g[p1].rL = yy - y;
        }
    }
    void DFS(vector<vector<int>>& maze, int x, int y, int lastX, int lastY) {
        if (lastX != -1) {
            CreateEdge(lastX, lastY, x, y);
        }
        if (maze[x][y] == -1) return;
        if (maze[x][y] == 2) return;
        maze[x][y] = 2;
        if (x > 0 && maze[x-1][y] != 1) {
            int newP = x - 1;
            while (newP >= 0 && maze[newP][y] != 1 && maze[newP][y] != -1) newP--;
            if (newP < 0 || maze[newP][y] == 1) newP++;
            DFS(maze, newP, y, x, y);
        }
        if (y > 0 && maze[x][y-1] != 1) {
            int newP = y - 1;
            while (newP >= 0 && maze[x][newP] != 1 && maze[x][newP] != -1) newP--;
            if (newP < 0 || maze[x][newP] == 1) newP++;
            DFS(maze, x, newP, x, y);
        }
        if (x < maze.size() - 1 && maze[x+1][y] != 1) {
            int newP = x + 1;
            while (newP < maze.size() && maze[newP][y] != 1 && maze[newP][y] != -1) newP++;
            if (newP >= maze.size() || maze[newP][y] == 1) newP--;
            DFS(maze, newP, y, x, y);
        }
        if (y < maze[x].size() - 1 && maze[x][y+1] != 1) {
            int newP = y + 1;
            while (newP < maze[x].size() && maze[x][newP] != 1 && maze[x][newP] != -1) newP++;
            if (newP >= maze[x].size() || maze[x][newP] == 1) newP--;
            DFS(maze, x, newP, x, y);
        }
    }
    void Dij(Pos start, Pos end) {
        priority_queue<pair<Pos, SV>, vector<pair<Pos, SV>>, cmp> heap;
        Pos stop = make_pair(-1, -1);
        heap.push(make_pair(start, SV(0, "")));
        while (!heap.empty()) {
            Pos pos = heap.top().first;
            int dis = heap.top().second.dis;
            string dir = heap.top().second.dir;
            heap.pop();
            auto it = g.find(pos);
            if (it == g.end()) continue;
            if (it->second.arr) continue;
            it->second.dis = dis;
            it->second.arr = true;
            it->second.fromDir = dir;
            if (pos == end) return;
            if (it->second.l != stop && !g[it->second.l].arr)
                heap.push(make_pair(it->second.l, SV(it->second.lL + dis, dir + "l")));
            if (it->second.r != stop && !g[it->second.r].arr)
                heap.push(make_pair(it->second.r, SV(it->second.rL + dis, dir + "r")));
            if (it->second.d != stop && !g[it->second.d].arr)
                heap.push(make_pair(it->second.d, SV(it->second.dL + dis, dir + "d")));
            if (it->second.u != stop && !g[it->second.u].arr)
                heap.push(make_pair(it->second.u, SV(it->second.uL + dis, dir + "u")));
        }
    }
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        g.clear();
        Pos beg = make_pair(ball[0], ball[1]);
        Pos tar = make_pair(hole[0], hole[1]);
        if (beg == tar) return "";
        maze[hole[0]][hole[1]] = -1;
        DFS(maze, ball[0], ball[1], -1, -1);

        Dij(beg, tar);
        if (g[tar].dis == 0) return "impossible";
        return g[tar].fromDir;
    }
};