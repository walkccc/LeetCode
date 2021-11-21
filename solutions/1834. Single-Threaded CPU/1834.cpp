class Solution {
 public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    const int n = tasks.size();

    // add index information
    for (int i = 0; i < tasks.size(); ++i)
      tasks[i].push_back(i);

    vector<int> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int i = 0;      // tasks' pointer
    long time = 0;  // current time

    sort(begin(tasks), end(tasks));

    while (i < n || !pq.empty()) {
      if (pq.empty())
        time = max(time, (long)tasks[i][0]);
      while (i < n && time >= tasks[i][0]) {
        pq.emplace(tasks[i][1], tasks[i][2]);
        ++i;
      }
      const auto [procTime, index] = pq.top();
      pq.pop();
      time += procTime;
      ans.push_back(index);
    }

    return ans;
  }
};
