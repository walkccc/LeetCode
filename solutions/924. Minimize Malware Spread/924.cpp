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
  int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
    const int n = graph.size();
    UnionFind uf(n);
    vector<int> ufSize(n);
    vector<int> malwareCount(n);

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        if (graph[i][j] == 1)
          uf.unionByRank(i, j);

    for (int i = 0; i < n; ++i)
      ++ufSize[uf.find(i)];

    for (const int i : initial)
      ++malwareCount[uf.find(i)];

    ranges::sort(initial);

    int ans = initial[0];
    int maxUfSize = 0;

    // Find the maximum union's malware if it only contains 1 malware.
    for (const int i : initial) {
      const int id = uf.find(i);
      if (ufSize[id] > maxUfSize && malwareCount[id] == 1) {
        maxUfSize = ufSize[id];
        ans = i;
      }
    }

    return ans;
  }
};
