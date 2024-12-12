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
  int largestComponentSize(vector<int>& nums) {
    const int n = ranges::max(nums);
    int ans = 0;
    UnionFind uf(n + 1);
    unordered_map<int, int> count;

    for (const int num : nums)
      for (int x = 2; x <= sqrt(num); ++x)
        if (num % x == 0) {
          uf.unionByRank(num, x);
          uf.unionByRank(num, num / x);
        }

    for (const int num : nums)
      ans = max(ans, ++count[uf.find(num)]);

    return ans;
  }
};
