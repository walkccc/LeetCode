class UF {
 public:
  int groupsCount;

  UF(int n) : rank(n), parent(n), groupsCount(n) {
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }

  void union_(int u, int v) {
    const int pu = find(u);
    const int pv = find(v);
    if (pu == pv) return;

    --groupsCount;
    if (rank[pu] < rank[pv])
      parent[pu] = pv;
    else if (rank[pu] > rank[pv])
      parent[pv] = pu;
    else {
      parent[pu] = pv;
      ++rank[pv];
    }
  }

 private:
  int find(int u) {
    if (parent[u] != u)
      parent[u] = find(parent[u]);
    return parent[u];
  }

  vector<int> rank;
  vector<int> parent;
};

class Solution {
 public:
  int minSwapsCouples(vector<int>& row) {
    const int n = row.size() / 2;
    UF uf(n);

    for (int i = 0; i < n; ++i) {
      const int a = row[2 * i];
      const int b = row[2 * i + 1];
      uf.union_(a / 2, b / 2);
    }

    return n - uf.groupsCount;
  }
};