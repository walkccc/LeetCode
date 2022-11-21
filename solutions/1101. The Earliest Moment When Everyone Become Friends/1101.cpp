class UnionFind {
 public:
  UnionFind(int n) : count(n), id(n), rank(n) {
    iota(begin(id), end(id), 0);
  }

  void union_(int u, int v) {
    int i = find(u);
    int j = find(v);
    if (i == j)
      return;
    if (rank[i] > rank[j])
      swap(i, j);
    else if (rank[i] == rank[j])
      ++rank[j];
    id[i] = j;
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
    sort(
        begin(logs), end(logs),
        [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

    for (const vector<int>& log : logs) {
      const int timestamp = log[0];
      const int x = log[1];
      const int y = log[2];
      uf.union_(x, y);
      if (uf.getCount() == 1)
        return timestamp;
    }

    return -1;
  }
};
