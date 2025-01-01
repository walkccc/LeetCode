class UnionFind {
 public:
  UnionFind(int n) : id(n), rank(n) {
    iota(id.begin(), id.end(), 0);
  }

  bool unionByRank(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return false;
    if (rank[i] < rank[j]) {
      id[i] = j;
    } else if (rank[i] > rank[j]) {
      id[j] = i;
    } else {
      id[i] = j;
      ++rank[j];
    }
    return true;
  }

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }

 private:
  vector<int> id;
  vector<int> rank;
};

class Solution {
 public:
  vector<bool> areConnected(int n, int threshold,
                            vector<vector<int>>& queries) {
    vector<bool> ans;
    UnionFind uf(n + 1);

    for (int z = threshold + 1; z <= n; ++z)
      for (int x = z * 2; x <= n; x += z)
        uf.unionByRank(z, x);

    for (const vector<int>& query : queries) {
      const int a = query[0];
      const int b = query[1];
      ans.push_back(uf.find(a) == uf.find(b));
    }

    return ans;
  }
};
