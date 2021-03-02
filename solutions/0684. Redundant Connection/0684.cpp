class UF {
 public:
  UF(int n) : parent(n) {
    iota(begin(parent), end(parent), 0);
  }

  bool union_(int u, int v) {
    const int pu = find(u);
    const int pv = find(v);
    if (pu == pv)
      return false;

    parent[pu] = pv;
    return true;
  }

 private:
  vector<int> parent;

  int find(int u) {
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }
};

class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    UF uf(edges.size() + 1);

    for (const auto& edge : edges)
      if (!uf.union_(edge[0], edge[1]))
        return edge;

    throw;
  }
};
