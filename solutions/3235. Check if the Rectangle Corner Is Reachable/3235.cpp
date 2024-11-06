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
  bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
    const int n = circles.size();
    // Add two virtual nodes, where node n represents (0, 0) and node n + 1
    // represents (X, Y).
    UnionFind uf(n + 2);

    // Iterate through each circle.
    for (int i = 0; i < n; ++i) {
      const int x = circles[i][0];
      const int y = circles[i][1];
      const int r = circles[i][2];
      // Union the current circle with the node (0, 0) if the circle overlaps
      // with the left or top edges.
      if (x - r <= 0 || y + r >= Y)
        uf.unionByRank(i, n);
      // Union the current circle with the node (X, Y) if the circle overlaps
      // with the right or bottom edges.
      if (x + r >= X || y - r <= 0)
        uf.unionByRank(i, n + 1);
      // Union the current circle with previous circles if they overlap.
      for (int j = 0; j < i; ++j) {
        const int x2 = circles[j][0];
        const int y2 = circles[j][1];
        const int r2 = circles[j][2];
        if (static_cast<long>(x - x2) * (x - x2) +
                static_cast<long>(y - y2) * (y - y2) <=
            static_cast<long>(r + r2) * (r + r2))
          uf.unionByRank(i, j);
      }
    }

    // If nodes (0, 0) and (X, Y) are in the same union set, that means there's
    // a path of overlapping circles that connects the left or top edges to the
    // right or bottom edges, implying that (0, 0) cannot reach (X, Y).
    return uf.find(n) != uf.find(n + 1);
  }
};
