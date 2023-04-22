#include<string>
using namespace std;
// LCA
inline int Max(int a, int b){return a>b?a:b;}

class Solution {
public:
    int f[510][510];
    int minDistance(string word1, string word2) {
        for(int i=0;i<word1.length();i++)
            for(int j=0;j<word2.length();j++) {
                f[i][j]=0;
                if(i!=0) f[i][j]=Max(f[i][j], f[i-1][j]);
                if(j!=0) f[i][j]=Max(f[i][j], f[i][j-1]);
                if(word1[i]==word2[j]) {
                    if(i==0 || j==0)
                        f[i][j]=Max(f[i][j], 1);
                    else f[i][j]=Max(f[i][j], f[i-1][j-1]+1);
                } 
            }
        return word1.length()+word2.length()-(f[word1.length()-1][word2.length()-1]*2);
    }
};
