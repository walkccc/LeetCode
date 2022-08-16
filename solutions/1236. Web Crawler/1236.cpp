/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *  public:
 *   vector<string> getUrls(string url);
 * };
 */

class Solution {
 public:
  vector<string> crawl(string startUrl, HtmlParser htmlParser) {
    queue<string> q{{startUrl}};
    unordered_set<string> seen{{startUrl}};
    const string& hostname = getHostname(startUrl);

    while (!q.empty()) {
      const string currUrl = q.front();
      q.pop();
      for (const string& url : htmlParser.getUrls(currUrl)) {
        if (seen.count(url))
          continue;
        if (url.find(hostname) != string::npos) {
          q.push(url);
          seen.insert(url);
        }
      }
    }

    return {begin(seen), end(seen)};
  }

 private:
  string getHostname(const string& url) {
    const int firstSlash = url.find_first_of('/');
    const int thirdSlash = url.find_first_of('/', firstSlash + 2);
    return url.substr(firstSlash + 2, thirdSlash - firstSlash - 2);
  }
};
