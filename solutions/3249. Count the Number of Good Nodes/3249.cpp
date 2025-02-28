class Solution {
 public:
  int countGoodNodes(vector<vector<int>>& edges) {
    const int n = edges.size() + 1;
    int ans = 0;
    vector<vector<int>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    dfs(graph, 0, /*prev=*/-1, ans);
    return ans;
  }

 private:
  int ans = 0;

  // Returns the size of the subtree rooted at u.
  int dfs(const vector<vector<int>>& graph, int u, int prev, int& ans) {
    int size = 1;
    vector<int> childrenSizes;

    for (const int v : graph[u]) {
      if (v == prev)
        continue;
      const int childSize = dfs(graph, v, u, ans);
      size += childSize;
      childrenSizes.push_back(childSize);
    }

    if (childrenSizes.empty() || allSameSizes(childrenSizes))
      ++ans;

    return size;
  }

 private:
  bool allSameSizes(const vector<int>& childrenSizes) {
    for (int i = 1; i < childrenSizes.size(); ++i)
      if (childrenSizes[i] != childrenSizes[0])
        return false;
    return true;
  }
};
