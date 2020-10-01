class Solution {
 public:
  int countComponents(int n, vector<vector<int>>& edges) {
    int ans = 0;
    vector<vector<int>> graph(n);
    unordered_set<int> seen;

    for (const vector<int>& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    function<void(int)> bfs = [&](int node) {
      queue<int> q{{node}};
      seen.insert(node);

      while (!q.empty()) {
        const int curr = q.front();
        q.pop();
        for (const int neighbor : graph[curr])
          if (!seen.count(neighbor)) {
            q.push(neighbor);
            seen.insert(neighbor);
          }
      }
    };

    for (int i = 0; i < n; ++i)
      if (!seen.count(i)) {
        bfs(i);
        ++ans;
      }

    return ans;
  }
};