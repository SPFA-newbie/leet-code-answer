#include<string>
#include<vector>
#include<queue>
using namespace std;

inline bool isLetter(char x) {
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

class StringIterator {
public:
    queue<pair<char, int>> list;
    StringIterator(string compressedString) {
        int pos = 1;
        char letter = compressedString[0];
        string num;
        while (pos != compressedString.length()) {
            if (isLetter(compressedString[pos])) {
                list.push(make_pair(letter, stoi(num)));
                num = "";
                letter = compressedString[pos];
                pos++;
                continue;
            }
            num.push_back(compressedString[pos]);
            pos++;
        }
        list.push(make_pair(letter, stoi(num)));
    }
    
    char next() {
        if (list.empty()) return ' ';
        list.front().second--;
        char ans = list.front().first;
        if (list.front().second == 0) list.pop();
        return ans;
    }
    
    bool hasNext() {
        return !list.empty();
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */