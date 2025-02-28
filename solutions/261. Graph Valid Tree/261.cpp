class Solution {
 public:
  bool validTree(int n, vector<vector<int>>& edges) {
    if (n == 0 || edges.size() != n - 1)
      return false;

    vector<vector<int>> graph(n);
    queue<int> q{{0}};
    unordered_set<int> seen{{0}};

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      for (const int v : graph[u])
        if (!seen.contains(v)) {
          q.push(v);
          seen.insert(v);
        }
    }

    return seen.size() == n;
  }
};
