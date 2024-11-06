class UnionFind {
 public:
  UnionFind(int n) : id(n) {
    iota(id.begin(), id.end(), 0);
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
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    string ans;
    UnionFind uf(26);

    for (int i = 0; i < s1.length(); ++i)
      uf.union_(s1[i] - 'a', s2[i] - 'a');

    for (const char c : baseStr)
      ans += 'a' + uf.find(c - 'a');

    return ans;
  }
};
