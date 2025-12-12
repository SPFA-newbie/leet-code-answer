#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nmap;
        for (int i = 0; i < nums2.size(); i++) {
            nmap.insert(make_pair(nums2[i], i));
        }
        vector<int> ans;
        for (int n: nums1) {
            ans.push_back(nmap.find(n)->second);
        }
        return ans;
    }
};