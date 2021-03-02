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
  int numSimilarGroups(vector<string>& A) {
    UF uf(A.size());

    for (int i = 1; i < A.size(); ++i)
      for (int j = 0; j < i; ++j)
        if (isSimilar(A[i], A[j]))
          uf.union_(i, j);

    return uf.getSize();
  }

 private:
  bool isSimilar(const string& X, const string& Y) {
    int diff = 0;
    for (int i = 0; i < X.length(); ++i)
      if (X[i] != Y[i] && ++diff > 2)
        return false;
    return true;
  }
};
