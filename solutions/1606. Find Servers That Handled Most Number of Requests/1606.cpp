class Solution {
 public:
  vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    vector<int> ans;
    vector<int> times(k);
    set<int> idleServers;
    // (endTime, server)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

    for (int i = 0; i < k; ++i)
      idleServers.insert(i);

    for (int i = 0; i < arrival.size(); ++i) {
      // Pop all the servers that are available now.
      while (!minHeap.empty() && minHeap.top().first <= arrival[i]) {
        idleServers.insert(minHeap.top().second);
        minHeap.pop();
      }
      // Get the next available server.
      const int server = getNextAvailableServer(idleServers, i, k);
      if (server == -1)
        continue;
      ++times[server];
      minHeap.emplace(arrival[i] + load[i], server);
      idleServers.erase(server);
    }

    const int busiest = ranges::max(times);
    for (int i = 0; i < k; ++i)
      if (times[i] == busiest)
        ans.push_back(i);
    return ans;
  }

 private:
  int getNextAvailableServer(const set<int>& idleServers, int ithRequest,
                             int k) {
    if (idleServers.empty())
      return -1;
    const auto it = idleServers.lower_bound(ithRequest % k);
    return it == idleServers.cend() ? *idleServers.begin() : *it;
  }
};
