#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    string parseTernary(string expression) {
        stack<char> st;
        int i = 0;
        while (i < expression.length()) {
            if (expression[i] != ':') {
                st.push(expression[i]);
                i++;
            } else {
                char l = st.top();
                i++, st.pop(), st.pop();
                if (st.top() == 'T') {
                    st.pop();
                    st.push(l);
                    int dep = 1;
                    i--;
                    while (dep != 0) {
                        i += 2;
                        if (i >= expression.length()) {
                            break;
                        }
                        if (expression[i] == ':') {
                            dep--;
                        } else if (expression[i] == '?'){
                            dep++;
                        }
                    }
                } else {
                    st.pop();
                }
            }
        }
        string ans = "";
        ans.push_back(st.top());
        return ans;
    }
};