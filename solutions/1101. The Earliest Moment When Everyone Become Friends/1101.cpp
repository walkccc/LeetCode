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
  int earliestAcq(vector<vector<int>>& logs, int n) {
    UnionFind uf(n);

    // Sort `logs` by timestamp.
    ranges::sort(logs, ranges::less{},
                 [](const vector<int>& log) { return log[0]; });

    for (const vector<int>& log : logs) {
      const int timestamp = log[0];
      const int x = log[1];
      const int y = log[2];
      uf.unionByRank(x, y);
      if (uf.getCount() == 1)
        return timestamp;
    }

    return -1;
  }
};
