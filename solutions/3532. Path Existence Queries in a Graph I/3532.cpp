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
  vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                    vector<vector<int>>& queries) {
    vector<bool> ans;
    UnionFind uf(n);

    for (int i = 1; i < n; ++i)
      if (abs(nums[i] - nums[i - 1]) <= maxDiff)
        uf.unionByRank(i, i - 1);

    for (const vector<int>& query : queries) {
      const int u = query[0];
      const int v = query[1];
      ans.push_back(uf.find(u) == uf.find(v));
    }

    return ans;
  }
};
