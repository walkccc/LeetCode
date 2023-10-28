class Solution {
 public:
  int countComponents(int n, vector<vector<int>>& edges) {
    int ans = 0;
    vector<vector<int>> graph(n);
    unordered_set<int> seen;

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    for (int i = 0; i < n; ++i)
      if (!seen.count(i)) {
        bfs(graph, i, seen);
        ++ans;
      }

    return ans;
  }

 private:
  void bfs(const vector<vector<int>>& graph, int node,
           unordered_set<int>& seen) {
    queue<int> q{{node}};
    seen.insert(node);

    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      for (const int v : graph[u])
        if (!seen.count(v)) {
          q.push(v);
          seen.insert(v);
        }
    }
  }
};
