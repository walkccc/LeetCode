class Solution {
 public:
  int checkWays(vector<vector<int>>& pairs) {
    constexpr int kMax = 501;
    unordered_map<int, vector<int>> graph;
    vector<int> degrees(kMax);
    vector<vector<bool>> connected(kMax, vector<bool>(kMax));

    for (const vector<int>& pair : pairs) {
      const int u = pair[0];
      const int v = pair[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
      ++degrees[u];
      ++degrees[v];
      connected[u][v] = true;
      connected[v][u] = true;
    }

    // For each node, sort its children by degrees in descending order.
    for (auto& [_, children] : graph)
      ranges::sort(children, [&degrees](int a, int b) {
        return degrees[b] < degrees[a];
      });

    const int root = getRoot(degrees, graph.size());
    if (root == -1)
      return 0;
    if (!dfs(graph, root, degrees, connected, {}, vector<bool>(kMax)))
      return 0;
    return hasMoreThanOneWay ? 2 : 1;
  }

 private:
  bool hasMoreThanOneWay = false;

  // Returns the root by finding the node with a degree that equals to n - 1.
  int getRoot(const vector<int>& degrees, int n) {
    for (int i = 1; i < degrees.size(); ++i)
      if (degrees[i] == n - 1)
        return i;
    return -1;
  }

  // Returns true if each node rooted at u is connected to all of its ancestors.
  bool dfs(const unordered_map<int, vector<int>>& graph, int u,
           vector<int>& degrees, vector<vector<bool>>& connected,
           vector<int>&& ancestors, vector<bool>&& seen) {
    seen[u] = true;

    for (const int ancestor : ancestors)
      if (!connected[u][ancestor])
        return false;

    ancestors.push_back(u);

    for (const int v : graph.at(u)) {
      if (seen[v])
        continue;
      // We can swap u with v, so there are more than one way.
      if (degrees[v] == degrees[u])
        hasMoreThanOneWay = true;
      if (!dfs(graph, v, degrees, connected, move(ancestors), move(seen)))
        return false;
    }

    ancestors.pop_back();
    return true;
  }
};
