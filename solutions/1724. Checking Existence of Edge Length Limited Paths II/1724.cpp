class UF {
 public:
  UF() {
  }
  UF(int n) {
    parent.resize(n);

    for (int i = 0; i < n; ++i)
      parent[i][0] = i;
  }

  void union_(int u, int v, int limit) {
    const int pu = find(u, limit);
    const int pv = find(v, limit);
    if (pu == pv)
      return;
    parent[pu][limit] = pv;
  }

  int find(int u, int limit) {
    // min iterator of parent[u] > limit
    const auto it = parent[u].upper_bound(limit);
    const int pu = prev(it)->second;
    if (pu == u)
      return u;
    // recursively find pu's parent
    const int ppu = find(pu, limit);
    parent[u][limit] = ppu;
    return ppu;
  }

 private:
  // parent[i]'s (key, value) := (limit, parent of node i <= limit)
  vector<map<int, int>> parent;
};

class DistanceLimitedPathsExist {
 public:
  DistanceLimitedPathsExist(int n, vector<vector<int>>& edgeList) {
    uf = UF(n);

    sort(begin(edgeList), end(edgeList),
         [](const auto& a, const auto& b) { return a[2] < b[2]; });

    for (const auto& edge : edgeList) {
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
  UF uf;
};
