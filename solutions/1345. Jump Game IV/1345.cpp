class Solution {
 public:
  int minJumps(vector<int>& arr) {
    const int n = arr.size();
    // {a: indices}
    unordered_map<int, vector<int>> graph;
    queue<int> q{{0}};
    vector<bool> seen(n);
    seen[0] = true;

    for (int i = 0; i < n; ++i)
      graph[arr[i]].push_back(i);

    for (int step = 0; !q.empty(); ++step) {
      for (int sz = q.size(); sz > 0; --sz) {
        const int i = q.front();
        q.pop();
        if (i == n - 1)
          return step;
        seen[i] = true;
        const int u = arr[i];
        if (i + 1 < n)
          graph[u].push_back(i + 1);
        if (i - 1 >= 0)
          graph[u].push_back(i - 1);
        for (const int v : graph[u]) {
          if (seen[v])
            continue;
          q.push(v);
        }
        graph[u].clear();
      }
    }

    throw;
  }
};
