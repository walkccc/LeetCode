class UF {
 public:
  UF(int n) : rank(n), parent(n) {
    for (int i = 0; i < n; ++i) parent[i] = i;
  }

  void union_(int u, int v) {
    const int pu = find(u);
    const int pv = find(v);
    if (pu == pv) return;

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
    if (u != parent[u]) parent[u] = find(parent[u]);
    return parent[u];
  }

 private:
  vector<int> rank;
  vector<int> parent;
};

class Solution {
 public:
  bool validTree(int n, vector<vector<int>>& edges) {
    if (n == 0 || edges.size() != n - 1) return false;

    UF uf(n);
    unordered_set<int> parents;

    for (const vector<int>& edge : edges) uf.union_(edge[0], edge[1]);

    for (int i = 0; i < n; ++i) parents.insert(uf.find(i));

    return parents.size() == 1;
  }
};