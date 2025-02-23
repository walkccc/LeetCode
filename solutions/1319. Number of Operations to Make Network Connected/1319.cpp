class Solution {
 public:
  int makeConnected(int n, vector<vector<int>>& connections) {
    // To connect n nodes, we need at least n - 1 edges
    if (connections.size() < n - 1)
      return -1;

    int numOfConnected = 0;
    vector<vector<int>> graph(n);
    unordered_set<int> seen;

    for (const vector<int>& connection : connections) {
      const int u = connection[0];
      const int v = connection[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    for (int i = 0; i < n; ++i)
      if (seen.insert(i).second) {
        dfs(graph, i, seen);
        ++numOfConnected;
      }

    return numOfConnected - 1;
  }

 private:
  void dfs(const vector<vector<int>>& graph, int u, unordered_set<int>& seen) {
    for (const int v : graph[u])
      if (seen.insert(v).second)
        dfs(graph, v, seen);
  }
};
