class Solution {
 public:
  int treeDiameter(vector<vector<int>>& edges) {
    const int n = edges.size();

    int ans = 0;
    vector<vector<int>> graph(n + 1);

    for (const auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    maxDepth(graph, 0, -1, ans);

    return ans;
  }

 private:
  int maxDepth(const vector<vector<int>>& graph, int node, int parent,
               int& ans) {
    int maxDepth1 = 0;   // the max depth
    int maxDepth2 = -1;  // the 2nd max depth

    for (const int child : graph[node]) {
      if (child == parent)
        continue;
      const int depth = maxDepth(graph, child, node, ans);
      if (depth > maxDepth1) {
        maxDepth2 = maxDepth1;
        maxDepth1 = depth;
      } else if (depth > maxDepth2) {
        maxDepth2 = depth;
      }
    }

    ans = max(ans, maxDepth1 + maxDepth2);

    return 1 + maxDepth1;
  }
};
