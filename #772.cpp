#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<string>
using namespace std;

#define TOP words[words.size()-1]

enum TYPE {
    NUM, ADD, SUB, MUL, DIV, LEFT, RIGHT
};

struct Word {
    int val;
    TYPE type;
    Word(TYPE _type, int _val) {
        type = _type;
        val = _val;
    }
    Word(char c) {
        switch(c) {
            case '+': type = ADD; break;
            case '-': type = SUB; break;
            case '*': type = MUL; break;
            case '/': type = DIV; break;
            case '(': type = LEFT; break;
            case ')': type = RIGHT; break;
        }
    }
    int op(Word a, Word b) {
        if (a.type != NUM || b.type != NUM) return 0;
        switch (type) {
            case ADD: return a.val + b.val;
            case SUB: return a.val - b.val;
            case MUL: return a.val * b.val;
            case DIV: return a.val / b.val;
        }
        return 0;
    }
};

class Solution {
public:
    Word calc(vector<Word>& words, int start) {
        int oppos = start + 1;
        Word res = words[start];
        while (oppos < words.size()) {
            res.val = words[oppos].op(res, words[oppos+1]);
            oppos += 2;
        }
        words.erase(words.begin() + start, words.end());
        return res;
    }
    int calculate(string s) {
        vector<Word> words;
        stack<int> pares;
        int i = 0;
        string num;
        while (i != s.length()) {
            if (s[i] >= '0' && s[i] <= '9') {
                num.push_back(s[i]);
                i++;
            } else {
                if (num.length() != 0) {
                    if (words.size() != 0 && (TOP.type == MUL || TOP.type == DIV)) {
                        Word op = TOP;
                        words.pop_back();
                        TOP.val = op.op(TOP, Word(NUM, stoi(num)));
                        num = "";
                    } else {
                        words.push_back(Word(NUM, stoi(num)));
                        num = "";
                    }
                }
                Word now = Word(s[i]);
                if (now.type != LEFT && now.type != RIGHT) {
                    words.push_back(now);
                } else if (now.type == LEFT) {
                    words.push_back(now);
                    pares.push(words.size());
                } else {
                    Word pareVal = calc(words, pares.top());
                    words.pop_back();
                    if (words.size() != 0 && (TOP.type == MUL || TOP.type == DIV)) {
                        Word op = TOP;
                        words.pop_back();
                        TOP.val = op.op(TOP, pareVal);
                        num = "";
                    } else {
                        words.push_back(pareVal);
                        num = "";
                    }
                    pares.pop();
                }
                i++;
            }
        }
        if (num.length() != 0) {
            if (words.size() != 0 && (TOP.type == MUL || TOP.type == DIV)) {
                Word op = TOP;
                words.pop_back();
                TOP.val = op.op(TOP, Word(NUM, stoi(num)));
            } else {
                words.push_back(Word(NUM, stoi(num)));
            }
        }
        return calc(words, 0).val;
    }
};