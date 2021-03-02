class Solution {
 public:
  int countComponents(int n, vector<vector<int>>& edges) {
    int ans = 0;
    vector<vector<int>> graph(n);
    unordered_set<int> seen;

    for (const auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
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
      const int curr = q.front();
      q.pop();
      for (const int child : graph[curr])
        if (!seen.count(child)) {
          q.push(child);
          seen.insert(child);
        }
    }
  }
};
