// ͵��������ʹ��STL���ȥ
// ����Ӧ����ʹ��KMP
#include<string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int tar=haystack.find(needle);
        if(tar==haystack.length())
            tar=-1;
        return tar;
    }
};
