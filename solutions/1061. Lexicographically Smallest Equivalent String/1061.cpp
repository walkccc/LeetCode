class UnionFind {
 public:
  UnionFind(int n) : id(n) {
    iota(begin(id), end(id), 0);
  }

  void union_(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i > j)
      id[i] = j;
    else
      id[j] = i;
  }

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }

 private:
  vector<int> id;
};

class Solution {
 public:
  string smallestEquivalentString(string A, string B, string S) {
    string ans;
    UnionFind uf(26);

    for (int i = 0; i < A.length(); ++i)
      uf.union_(A[i] - 'a', B[i] - 'a');

    for (const char c : S)
      ans += (char)'a' + uf.find(c - 'a');

    return ans;
  }
};
