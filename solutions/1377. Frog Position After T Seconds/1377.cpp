class Solution {
 public:
  double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    vector<vector<int>> graph(n + 1);
    queue<int> q{{1}};
    vector<bool> seen(n + 1);
    vector<double> prob(n + 1);

    seen[1] = true;
    prob[1] = 1.0;

    for (const auto& e : edges) {
      const int u = e[0];
      const int v = e[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    while (!q.empty() && t-- > 0)
      for (int sz = q.size(); sz > 0; --sz) {
        const int a = q.front();
        q.pop();
        const int nChildren = count_if(begin(graph[a]), end(graph[a]),
                                       [&seen](int b) { return !seen[b]; });
        for (const int b : graph[a]) {
          if (seen[b])
            continue;
          seen[b] = true;
          prob[b] = prob[a] / nChildren;
          q.push(b);
        }
        if (nChildren > 0)
          prob[a] = 0.0;
      }

    return prob[target];
  }
};
