class UF {
 public:
  UF(int n) : size(n), rank(n), parent(n) {
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }

  void union_(int u, int v) {
    const int pu = find(u);
    const int pv = find(v);
    if (pu == pv) return;

    --size;
    if (rank[pu] < rank[pv])
      parent[pu] = pv;
    else if (rank[pv] < rank[pu])
      parent[pv] = pu;
    else {
      parent[pu] = pv;
      ++rank[pv];
    }
  }

  int find(int u) {
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }

  int getSize() {
    return size;
  }

 private:
  int size;
  vector<int> rank;
  vector<int> parent;
};

class Solution {
 public:
  int countComponents(int n, vector<vector<int>>& edges) {
    UF uf(n);

    for (const vector<int>& edge : edges)
      uf.union_(edge[0], edge[1]);

    return uf.getSize();
  }
};