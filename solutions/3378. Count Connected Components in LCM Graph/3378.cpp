class UnionFind {
 public:
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
    if (!id.contains(u))
      id[u] = u;
    return id[u] == u ? u : id[u] = find(id[u]);
  }

 private:
  unordered_map<int, int> id;
  unordered_map<int, int> rank;
};

class Solution {
 public:
  int countComponents(vector<int>& nums, int threshold) {
    UnionFind uf;

    for (const int num : nums)
      for (int multiple = 2 * num; multiple <= threshold; multiple += num)
        uf.unionByRank(num, multiple);

    unordered_set<int> components;
    for (const int num : nums)
      components.insert(uf.find(num));
    return components.size();
  }
};
