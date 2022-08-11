class UF {
 public:
  UF(int n) : count(n), id(n) {
    iota(begin(id), end(id), 0);
  }

  void union_(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return;
    id[i] = j;
    --count;
  }

  int getCount() const {
    return count;
  }

 private:
  int count;
  vector<int> id;

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
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

    return uf.getCount();
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
