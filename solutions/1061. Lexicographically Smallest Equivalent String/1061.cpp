class UF {
 public:
  UF(int n) : parent(n) {
    iota(begin(parent), end(parent), 0);
  }

  // pu > pv, so we assign the smaller to the bigger's parent
  void union_(int pu, int pv) {
    parent[pu] = pv;
  }

  int find(int u) {
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }

 private:
  vector<int> parent;
};

class Solution {
 public:
  string smallestEquivalentString(string A, string B, string S) {
    string ans;
    UF uf(26);

    for (int i = 0; i < A.length(); ++i) {
      const int a = A[i] - 'a';
      const int b = B[i] - 'a';
      const int pa = uf.find(a);
      const int pb = uf.find(b);
      if (pa > pb)
        uf.union_(pa, pb);
      else
        uf.union_(pb, pa);
    }

    for (const char c : S)
      ans += (char)'a' + uf.find(c - 'a');

    return ans;
  }
};
