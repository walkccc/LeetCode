class UnionFind {
 public:
  UnionFind() {}
  UnionFind(int n) {
    id.resize(n);

    for (int i = 0; i < n; ++i)
      id[i][0] = i;
  }

  void union_(int u, int v, int limit) {
    const int i = find(u, limit);
    const int j = find(v, limit);
    if (i == j)
      return;
    id[i][limit] = j;
  }

  int find(int u, int limit) {
    // the minimum iterator of id[u] > limit
    const auto it = id[u].upper_bound(limit);
    const int i = prev(it)->second;
    if (i == u)
      return u;
    // Recursively find i's id.
    const int j = find(i, limit);
    id[u][limit] = j;
    return j;
  }

 private:
  // id[i]'s (key, value) := (limit, id of node i <= limit)
  vector<map<int, int>> id;
};

class DistanceLimitedPathsExist {
 public:
  DistanceLimitedPathsExist(int n, vector<vector<int>>& edgeList) {
    uf = UnionFind(n);

    ranges::sort(edgeList,
                 [](const auto& a, const auto& b) { return a[2] < b[2]; });

    for (const vector<int>& edge : edgeList) {
      const int u = edge[0];
      const int v = edge[1];
      const int d = edge[2];
      uf.union_(u, v, d);
    }
  }

  bool query(int p, int q, int limit) {
    return uf.find(p, limit - 1) == uf.find(q, limit - 1);
  }

 private:
  UnionFind uf;
};
