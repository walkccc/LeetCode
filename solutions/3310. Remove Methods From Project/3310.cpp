class Solution {
 public:
  vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    vector<int> ans;
    vector<vector<int>> graph(n);

    for (const vector<int>& invocation : invocations) {
      const int u = invocation[0];
      const int v = invocation[1];
      graph[u].push_back(v);
    }

    queue<int> q{{k}};
    vector<bool> seen(n);
    seen[k] = true;

    while (!q.empty())
      for (int sz = q.size(); sz > 0; --sz) {
        const int u = q.front();
        q.pop();
        for (const int v : graph[u])
          if (!seen[v]) {
            q.push(v);
            seen[v] = true;
          }
      }

    for (int u = 0; u < n; ++u) {
      if (seen[u])
        continue;
      for (const int v : graph[u])
        if (seen[v]) {
          ans.resize(n);
          iota(ans.begin(), ans.end(), 0);
          return ans;
        }
      ans.push_back(u);
    }

    return ans;
  }
};
