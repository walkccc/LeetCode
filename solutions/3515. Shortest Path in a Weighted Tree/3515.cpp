class LazySegmentTree {
 public:
  explicit LazySegmentTree(int n) : n(n), tree(4 * n), lazy(4 * n) {}

  // Updates the range [l, r] by adding val.
  void addRange(int l, int r, int val) {
    addRange(0, 0, n - 1, l, r, val);
  }

  // Returns the value at index i.
  int query(int i) {
    return query(0, 0, n - 1, i);
  }

 private:
  const int n;       // the size of the input array
  vector<int> tree;  // the segment tree
  vector<int> lazy;  // the lazy propagation array

  void push(int treeIndex, int lo, int hi) {
    if (lazy[treeIndex] == 0)
      return;
    tree[treeIndex] += lazy[treeIndex];
    if (lo != hi) {
      lazy[2 * treeIndex + 1] += lazy[treeIndex];
      lazy[2 * treeIndex + 2] += lazy[treeIndex];
    }
    lazy[treeIndex] = 0;
  }

  void addRange(int treeIndex, int lo, int hi, int l, int r, int val) {
    push(treeIndex, lo, hi);
    if (r < lo || l > hi)  // [lo, hi] lies completely outside [l, r].
      return;
    if (l <= lo && hi <= r) {  // [lo, hi] lies completely inside [l, r].
      lazy[treeIndex] += val;
      push(treeIndex, lo, hi);
      return;
    }
    const int mid = (lo + hi) / 2;
    addRange(2 * treeIndex + 1, lo, mid, l, r, val);
    addRange(2 * treeIndex + 2, mid + 1, hi, l, r, val);
  }

  int query(int treeIndex, int lo, int hi, int i) {
    push(treeIndex, lo, hi);
    if (lo == hi)
      return tree[treeIndex];
    const int mid = (lo + hi) / 2;
    if (i <= mid)
      return query(2 * treeIndex + 1, lo, mid, i);
    return query(2 * treeIndex + 2, mid + 1, hi, i);
  }
};

class Solution {
 public:
  vector<int> treeQueries(int n, vector<vector<int>>& edges,
                          vector<vector<int>>& queries) {
    LazySegmentTree tree(n);
    vector<int> ans;
    vector<vector<pair<int, int>>> graph(n + 1);
    map<pair<int, int>, int> edgeWeights;

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int w = edge[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
      edgeWeights[{min(u, v), max(u, v)}] = w;
    }

    // DFS: Euler tour and parent/distance tracking
    vector<int> inTime(n + 1);
    vector<int> outTime(n + 1);
    vector<int> dist(n + 1);
    vector<int> parent(n + 1);
    int time = 0;

    dfs(graph, 1, /*prev=*/-1, time, inTime, outTime, dist, parent);

    for (int i = 1; i <= n; ++i)
      tree.addRange(inTime[i], inTime[i], dist[i]);

    for (const vector<int>& query : queries) {
      const int type = query[0];
      if (type == 1) {
        const int u = query[1];
        const int v = query[2];
        const int newWeight = query[3];
        const auto key = pair<int, int>{min(u, v), max(u, v)};
        const int oldWeight = edgeWeights[key];
        const int delta = newWeight - oldWeight;
        edgeWeights[key] = newWeight;
        // Find child node (the one that's not the parent)
        const int child = (parent[v] == u) ? v : u;
        tree.addRange(inTime[child], outTime[child], delta);
      } else {
        const int x = query[1];
        ans.push_back(tree.query(inTime[x]));
      }
    }

    return ans;
  }

 private:
  void dfs(const vector<vector<pair<int, int>>>& graph, int u, int prev,
           int& time, vector<int>& inTime, vector<int>& outTime,
           vector<int>& dist, vector<int>& parent) {
    inTime[u] = time++;
    for (const auto& [v, w] : graph[u]) {
      if (v == prev)
        continue;
      dist[v] = dist[u] + w;
      parent[v] = u;
      dfs(graph, v, u, time, inTime, outTime, dist, parent);
    }
    outTime[u] = time - 1;
  }
};
