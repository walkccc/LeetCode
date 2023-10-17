class UnionFind {
 public:
  UnionFind(int n) : count(n), id(n), rank(n) {
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
    --count;
    return true;
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
  int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    UnionFind alice(n);
    UnionFind bob(n);
    int requiredEdges = 0;

    // Greedily put type 3 edges in the front.
    sort(
        edges.begin(), edges.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[0] > b[0]; });

    for (const vector<int>& edge : edges) {
      const int type = edge[0];
      const int u = edge[1] - 1;
      const int v = edge[2] - 1;
      switch (type) {
        case 3:  // Can be traversed by Alice and Bob.
          // Note that we should use | instead of || because if the first
          // expression is true, short-circuiting will skip the second
          // expression.
          if (alice.unionByRank(u, v) | bob.unionByRank(u, v))
            ++requiredEdges;
          break;
        case 2:  // Can be traversed by Bob.
          if (bob.unionByRank(u, v))
            ++requiredEdges;
        case 1:  // Can be traversed by Alice.
          if (alice.unionByRank(u, v))
            ++requiredEdges;
      }
    }

    return alice.getCount() == 1 && bob.getCount() == 1
               ? edges.size() - requiredEdges
               : -1;
  }
};
