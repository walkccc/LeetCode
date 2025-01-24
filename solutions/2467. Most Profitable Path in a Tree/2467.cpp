class Solution {
 public:
  int mostProfitablePath(vector<vector<int>>& edges, int bob,
                         vector<int>& amount) {
    const int n = amount.size();
    vector<vector<int>> tree(n);
    vector<int> parent(n);
    vector<int> aliceDist(n, -1);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      tree[u].push_back(v);
      tree[v].push_back(u);
    }

    dfs(tree, 0, -1, 0, parent, aliceDist);

    // Modify the amount along the path from node Bob to node 0.
    // For each node,
    //   1. If Bob reaches earlier than Alice does, change the amount to 0.
    //   2. If Bob and Alice reach simultaneously, devide the amount by 2.
    for (int u = bob, bobDist = 0; u != 0; u = parent[u], ++bobDist)
      if (bobDist < aliceDist[u])
        amount[u] = 0;
      else if (bobDist == aliceDist[u])
        amount[u] /= 2;

    return getMoney(tree, 0, -1, amount);
  }

 private:
  // Fills `parent` and `dist`.
  void dfs(const vector<vector<int>>& tree, int u, int prev, int d,
           vector<int>& parent, vector<int>& dist) {
    parent[u] = prev;
    dist[u] = d;
    for (const int v : tree[u]) {
      if (dist[v] == -1)
        dfs(tree, v, u, d + 1, parent, dist);
    }
  }

  int getMoney(const vector<vector<int>>& tree, int u, int prev,
               const vector<int>& amount) {
    // a leaf node
    if (tree[u].size() == 1 && tree[u][0] == prev)
      return amount[u];

    int maxPath = INT_MIN;
    for (const int v : tree[u])
      if (v != prev)
        maxPath = max(maxPath, getMoney(tree, v, u, amount));

    return amount[u] + maxPath;
  }
};
