class UnionFind {
 public:
  UnionFind(int n) : id(n) {
    iota(id.begin(), id.end(), 0);
  }

  void union_(int u, int v) {
    id[find(u)] = find(v);
  }

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }

 private:
  vector<int> id;
};

class Solution {
 public:
  bool equationsPossible(vector<string>& equations) {
    UnionFind uf(26);

    for (const string& e : equations)
      if (e[1] == '=') {
        const int x = e[0] - 'a';
        const int y = e[3] - 'a';
        uf.union_(x, y);
      }

    for (const string& e : equations)
      if (e[1] == '!') {
        const int x = e[0] - 'a';
        const int y = e[3] - 'a';
        if (uf.find(x) == uf.find(y))
          return false;
      }

    return true;
  }
};
