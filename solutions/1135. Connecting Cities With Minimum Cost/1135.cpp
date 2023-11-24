class UnionFind {
 public:
  UnionFind(int n) : id(n), rank(n) {
    iota(id.begin(), id.end(), 0);
  }

  void unionByRank(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return;
    if (rank[i] < rank[j]) {
      id[i] = j;
    } else if (rank[i] > rank[j]) {
      id[j] = i;
    } else {
      id[i] = j;
      ++rank[j];
    }
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
  int minimumCost(int n, vector<vector<int>>& connections) {
    int ans = 0;
    UnionFind uf(n + 1);

    // Sort by cost.
    sort(
        connections.begin(), connections.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[2] < b[2]; });

    for (const vector<int>& c : connections) {
      const int u = c[0];
      const int v = c[1];
      const int cost = c[2];
      if (uf.find(u) == uf.find(v))
        continue;
      uf.unionByRank(u, v);
      ans += cost;
    }

    const int root = uf.find(1);
    for (int i = 1; i <= n; ++i)
      if (uf.find(i) != root)
        return -1;

    return ans;
  }
};
