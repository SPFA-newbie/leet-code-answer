#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
using namespace std;

class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string s = "";
        for (string& rs: strs) {
            for (char c: rs) {
                s.push_back(c);
                if (c == '#') {
                    s.push_back('#');
                }
            }
            s.push_back('#');
            s.push_back('E');
        }
        return s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        bool rec = false;
        string ns = "";
        for (char c: s) {
            if (c == '#') {
                if (rec) {
                    rec = false;
                    ns.push_back(c);
                } else {
                    rec = true;
                }
            } else if (c == 'E') {
                if (rec) {
                    rec = false;
                    ans.push_back(ns);
                    ns = "";
                } else {
                    ns.push_back(c);
                }
            } else {
                ns.push_back(c);
            }
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));