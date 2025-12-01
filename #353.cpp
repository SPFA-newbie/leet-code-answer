#include<string>
#include<vector>
#include<queue>
using namespace std;

class SnakeGame {
public:
    queue<pair<int, int>> snake;
    int x, y;
    int w, h;
    vector<vector<int>> foods;
    int pos;
    int point;
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        x = y = 0;
        w = width;
        h = height;
        foods = food;
        vector<int> theEnd;
        theEnd.push_back(-2);
        theEnd.push_back(-2);
        foods.push_back(theEnd);
        pos = 0;
        point = 0;
        snake.push(make_pair(x, y));
    }
    bool dieCheck() {
        if (x == w || x == -1 || y == h || y == -1) {
            return true;
        }
        queue<pair<int, int>> checker = snake;
        pair<int, int> now = make_pair(x, y);
        while (checker.size() > 1) {
            if (checker.front() == now) return true;
            checker.pop();
        }
        return false;
    }
    int move(string direction) {
        if (direction == "R") x++; else
        if (direction == "L") x--; else
        if (direction == "D") y++; else
        if (direction == "U") y--;
        snake.push(make_pair(x, y));
        if (y == foods[pos][0] && x == foods[pos][1]) {
            point++;
            pos++;
        } else {
            snake.pop();
        }
        if (dieCheck() == true) return -1;
        return point;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */