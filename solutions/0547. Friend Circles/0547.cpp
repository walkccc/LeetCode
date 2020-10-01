class UF {
 public:
  UF(int n) : rank(n), parent(n) {
    for (int i = 0; i < n; ++i)
      parent[i] = i;
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
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }

 private:
  vector<int> rank;
  vector<int> parent;
};

class Solution {
 public:
  int findCircleNum(vector<vector<int>>& M) {
    const int n = M.size();

    UF uf(n);
    unordered_set<int> friendCircles;

    for (int i = 0; i < n; ++i)
      for (int j = i; j < n; ++j)
        if (M[i][j] == 1)
          uf.union_(i, j);

    for (int i = 0; i < n; ++i)
      friendCircles.insert(uf.find(i));

    return friendCircles.size();
  }
};