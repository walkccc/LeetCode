class UF {
 public:
  UF() {}
  UF(int n) {
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
    // min iterator of id[u] > limit
    const auto it = id[u].upper_bound(limit);
    const int i = prev(it)->second;
    if (i == u)
      return u;
    // recursively find i's id
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
    uf = UF(n);

    sort(begin(edgeList), end(edgeList),
         [](const auto& a, const auto& b) { return a[2] < b[2]; });

    for (const auto& e : edgeList) {
      const int u = e[0];
      const int v = e[1];
      const int d = e[2];
      uf.union_(u, v, d);
    }
  }

  bool query(int p, int q, int limit) {
    return uf.find(p, limit - 1) == uf.find(q, limit - 1);
  }

 private:
  UF uf;
};
