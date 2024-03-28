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
    const int nThreads = std::thread::hardware_concurrency();
    vector<thread> threads;
    std::mutex mtx;
    std::condition_variable cv;

    auto t = [&]() {
      while (true) {
        unique_lock<mutex> lock(mtx);
        cv.wait_for(lock, 30ms, [&]() { return q.size(); });
        if (q.empty())
          return;
        auto cur = q.front();
        q.pop();
        lock.unlock();
        const vector<string> urls = htmlParser.getUrls(cur);
        lock.lock();
        for (const string& url : urls) {
          if (seen.count(url))
            continue;
          if (url.find(hostname) != string::npos) {
            q.push(url);
            seen.insert(url);
          }
        }
        lock.unlock();
        cv.notify_all();
      }
    };

    for (int i = 0; i < nThreads; ++i)
      threads.emplace_back(t);

    for (std::thread& t : threads)
      t.join();

    return {seen.begin(), seen.end()};
  }

 private:
  string getHostname(const string& url) {
    const int firstSlash = url.find_first_of('/');
    const int thirdSlash = url.find_first_of('/', firstSlash + 2);
    return url.substr(firstSlash + 2, thirdSlash - firstSlash - 2);
  }
};
