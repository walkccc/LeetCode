class Solution {
 public:
  int assignEdgeWeights(vector<vector<int>>& edges) {
    const int n = edges.size() + 1;
    vector<vector<int>> graph(n + 1);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    queue<int> q{{1}};
    vector<bool> seen(n + 1);
    seen[1] = true;
    int step = 0;

    for (step = 0; !q.empty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        const int u = q.front();
        q.pop();
        for (const int v : graph[u])
          if (!seen[v]) {
            q.push(v);
            seen[v] = true;
          }
      }

    return step > 0 ? modPow(2, step - 2) : 0;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % kMod, (n - 1)) % kMod;
    return modPow(x * x % kMod, (n / 2)) % kMod;
  }
};
