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
  int minSwapsCouples(vector<int>& row) {
    const int n = row.size() / 2;
    UF uf(n);

    for (int i = 0; i < n; ++i) {
      const int a = row[2 * i];
      const int b = row[2 * i + 1];
      uf.union_(a / 2, b / 2);
    }

    return n - uf.getSize();
  }
};
