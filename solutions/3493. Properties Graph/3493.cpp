class UnionFind {
 public:
  UnionFind(int n) : count(n), id(n), rank(n) {
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
    --count;
  }

  int getCount() const {
    return count;
  }

 private:
  int count;
  vector<int> id;
  vector<int> rank;

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }
};

class Solution {
 public:
  int numberOfComponents(vector<vector<int>>& properties, int k) {
    const int n = properties.size();
    const vector<set<int>> propertySets = getPropertySets(properties);
    UnionFind uf(n);

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        vector<int> intersection;
        std::set_intersection(propertySets[i].begin(), propertySets[i].end(),
                              propertySets[j].begin(), propertySets[j].end(),
                              std::back_inserter(intersection));
        if (intersection.size() >= k)
          uf.unionByRank(i, j);
      }

    return uf.getCount();
  }

 private:
  vector<set<int>> getPropertySets(const vector<vector<int>>& properties) {
    vector<set<int>> propertySets;
    for (const vector<int>& property : properties)
      propertySets.push_back({property.begin(), property.end()});
    return propertySets;
  }
};
