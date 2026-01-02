#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;


class Solution {
public:
    string siMul(string& num, int si, int zero) {
        stack<char> res;
        while (zero != 0) {
            res.push('0');
            zero--;
        }
        int up = 0;
        for (int i = num.length() - 1; i >= 0; i--) {
            int mul = si * (num[i] - '0') + up;
            res.push((char)mul % 10 + '0');
            up = mul / 10;
        }
        if (up != 0) {
            res.push((char)up + '0');
        }
        string ret;
        while (!res.empty()) {
            ret.push_back(res.top());
            res.pop();
        }
        return ret;
    }
    string strAdd(string& a, string b) {
        int posA = a.length() - 1;
        int posB = b.length() - 1;
        stack<char> res;
        bool up = false;
        while (posA >= 0 || posB >= 0) {
            int add = 0;
            if (posA >= 0) {
                add += a[posA] - '0';
            }
            if (posB >= 0) {
                add += b[posB] - '0';
            }
            if (up) add++;
            up = (add >= 10);
            res.push((char)add % 10 + '0');
            posA--, posB--;
        }
        if (up) {
            res.push('1');
        }
        string ret;
        while (!res.empty()) {
            ret.push_back(res.top());
            res.pop();
        }
        return ret;
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string ans = "0";
        for (int i = num2.length() - 1; i >= 0; i--) {
            ans = strAdd(ans, siMul(num1, num2[i] - '0', num2.length() - 1 - i));
        }
        return ans;
    }
};