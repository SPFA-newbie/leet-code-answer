#include<vector>
using namespace std;

class TicTacToe {
public:
    int n;
    vector<vector<int>> desk;
    TicTacToe(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) {
            vector<int> row;
            for (int j = 0; j < n; j++) {
                row.push_back(0);
            }
            desk.push_back(row);
        }
    }
    bool check(int row, int col, int player) {
        bool win[4] = {true, true, true, true};
        for (int i = 0; i < n; i++) {
            if (desk[row][i] != player) win[0] = false;
            if (desk[i][col] != player) win[1] = false;
        }
        if (row == col) {
            for (int i = 0; i < n; i++) {
                if (desk[i][i] != player) win[2] = false;
            }
        } else {
            win[2] = false;
        }
        if (row + col + 1 == n) {
            for (int i = 0; i < n; i++) {
                if (desk[n-i-1][i] != player) win[3] = false;
            }
        } else {
            win[3] = false;
        }
        return win[0] || win[1] || win[2] || win[3];
    }
    int move(int row, int col, int player) {
        desk[row][col] = player;
        if (check(row, col, player)) {
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */