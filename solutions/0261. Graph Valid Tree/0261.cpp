class Solution {
 public:
  bool validTree(int n, vector<vector<int>>& edges) {
    if (n == 0 || edges.size() != n - 1)
      return false;

    vector<vector<int>> graph(n);
    queue<int> q{{0}};
    unordered_set<int> seen;
    seen.insert(0);

    for (const vector<int> edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    while (!q.empty()) {
      const int node = q.front(); q.pop();
      for (const int neighbor : graph[node])
        if (!seen.count(neighbor)) {
          q.push(neighbor);
          seen.insert(neighbor);
        }
    }

    return seen.size() == n;
  }
};