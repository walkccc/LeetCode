struct T {
  int weight;
  int index;
  int freeTime;
  T(int weight, int index, int freeTime)
      : weight(weight), index(index), freeTime(freeTime) {}
};

class Solution {
 public:
  vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    const int n = servers.size();
    const int m = tasks.size();
    vector<int> ans(m);
    auto compareFree = [](const T& a, const T& b) {
      return a.weight == b.weight ? a.index > b.index : a.weight > b.weight;
    };
    auto compareUsed = [](const T& a, const T& b) {
      if (a.freeTime != b.freeTime)
        return a.freeTime > b.freeTime;
      if (a.weight != b.weight)
        return a.weight > b.weight;
      return a.index > b.index;
    };
    priority_queue<T, vector<T>, decltype(compareFree)> free(compareFree);
    priority_queue<T, vector<T>, decltype(compareUsed)> used(compareUsed);

    for (int i = 0; i < n; ++i)
      free.emplace(servers[i], i, 0);

    for (int i = 0; i < m; ++i) {  // i := the current time
      const int executionTime = tasks[i];
      // Pop all the servers that'll be free at time i.
      while (!used.empty() && used.top().freeTime <= i) {
        const T curr = used.top();
        used.pop();
        free.push(curr);
      }
      if (free.empty()) {
        T server = used.top();
        used.pop();
        ans[i] = server.index;
        server.freeTime += executionTime;
        used.push(server);
      } else {
        T server = free.top();
        free.pop();
        ans[i] = server.index;
        server.freeTime = i + executionTime;
        used.push(server);
      }
    }

    return ans;
  }
};
