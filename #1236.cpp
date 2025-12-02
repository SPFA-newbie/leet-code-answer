/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    string getHost(string& url) {
        string host = "";
        int pos = 7;
        while (pos < url.length() && url[pos] != '/') {
            host.push_back(url[pos]);
            pos++;
        }
        return host;
    }
    void DFS(vector<string>& ans, unordered_set<string>& arr, string url, HtmlParser& htmlParser, string& host) {
        if (arr.find(url) != arr.end()) return;
        ans.push_back(url);
        arr.insert(url);
        vector<string> urls = htmlParser.getUrls(url);
        for (auto next: urls) {
            if (getHost(next) == host) {
                DFS(ans, arr, next, htmlParser, host);
            }
        }
    }
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        unordered_set<string> arr;
        vector<string> ans;
        string host = getHost(startUrl);
        DFS(ans, arr, startUrl, htmlParser, host);
        return ans;
    }
};