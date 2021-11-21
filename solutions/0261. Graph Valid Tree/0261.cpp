class Solution {
 public:
  bool validTree(int n, vector<vector<int>>& edges) {
    if (n == 0 || edges.size() != n - 1)
      return false;

    vector<vector<int>> graph(n);
    queue<int> q{{0}};
    unordered_set<int> seen{{0}};

    for (const auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      for (const int v : graph[u])
        if (!seen.count(v)) {
          q.push(v);
          seen.insert(v);
        }
    }

    return seen.size() == n;
  }
};
