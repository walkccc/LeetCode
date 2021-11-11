class UF {
 public:
  UF(int n) : size(n), parent(n) {
    iota(begin(parent), end(parent), 0);
  }

  void union_(int u, int v) {
    const int pu = find(u);
    const int pv = find(v);
    if (pu == pv)
      return;

    parent[pu] = pv;
    --size;
  }

  int getSize() {
    return size;
  }

 private:
  int size;
  vector<int> parent;

  int find(int u) {
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }
};

class Solution {
 public:
  int countComponents(int n, vector<vector<int>>& edges) {
    UF uf(n);

    for (const auto& edge : edges)
      uf.union_(edge[0], edge[1]);

    return uf.getSize();
  }
};
