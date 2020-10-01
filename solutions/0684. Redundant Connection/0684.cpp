class UF {
 public:
  UF(int n) : rank(n), parent(n) {
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }

  bool union_(int u, int v) {
    const int pu = find(u);
    const int pv = find(v);
    if (pu == pv) return false;

    if (rank[pu] < rank[pv])
      parent[pu] = pv;
    else if (rank[pu] > rank[pv])
      parent[pv] = pu;
    else {
      parent[pu] = pv;
      ++rank[pv];
    }

    return true;
  }

 private:
  int find(int u) {
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }

  vector<int> rank;
  vector<int> parent;
};

class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    UF uf(edges.size() + 1);

    for (const vector<int>& edge : edges)
      if (!uf.union_(edge[0], edge[1]))
        return edge;

    throw;
  }
};