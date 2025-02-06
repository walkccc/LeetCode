class Solution {
 public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    const int n = tasks.size();

    // Add index information.
    for (int i = 0; i < tasks.size(); ++i)
      tasks[i].push_back(i);

    vector<int> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    int i = 0;      // tasks' index
    long time = 0;  // the current time

    ranges::sort(tasks);
    while (i < n || !minHeap.empty()) {
      if (minHeap.empty())
        time = max(time, static_cast<long>(tasks[i][0]));
      while (i < n && time >= tasks[i][0]) {
        minHeap.emplace(tasks[i][1], tasks[i][2]);
        ++i;
      }
      const auto [procTime, index] = minHeap.top();
      minHeap.pop();
      time += procTime;
      ans.push_back(index);
    }

    return ans;
  }
};
