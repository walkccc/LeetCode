class Solution {
 public:
  vector<int> closestNode(int n, vector<vector<int>>& edges,
                          vector<vector<int>>& query) {
    vector<int> ans;
    vector<vector<int>> tree(n);
    vector<vector<int>> dist(n, vector<int>(n, -1));

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      tree[u].push_back(v);
      tree[v].push_back(u);
    }

    for (int i = 0; i < n; ++i)
      fillDist(tree, i, i, 0, dist);

    for (const vector<int>& q : query) {
      const int start = q[0];
      const int end = q[1];
      const int node = q[2];
      ans.push_back(findClosest(tree, dist, start, end, node, start));
    }

    return ans;
  }

 private:
  void fillDist(const vector<vector<int>>& tree, int start, int u, int d,
                vector<vector<int>>& dist) {
    dist[start][u] = d;
    for (const int v : tree[u])
      if (dist[start][v] == -1)
        fillDist(tree, start, v, d + 1, dist);
  }

  int findClosest(const vector<vector<int>>& tree,
                  const vector<vector<int>>& dist, int u, int end, int node,
                  int ans) {
    for (const int v : tree[u])
      if (dist[v][end] < dist[u][end])
        return findClosest(tree, dist, v, end, node,
                           dist[ans][node] < dist[v][node] ? ans : v);
    return ans;
  }
};
