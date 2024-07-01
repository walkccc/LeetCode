class Solution {
 public:
  long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
    int ans = 0;
    vector<vector<int>> tree(n);
    // maxSums[i] := the maximum the sum of path rooted at i
    vector<int> maxSums(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      tree[u].push_back(v);
      tree[v].push_back(u);
    }

    // Precalculate `maxSums`.
    maxSum(tree, 0, /*prev=*/-1, maxSums, price);
    reroot(tree, 0, /*prev=*/-1, /*parentSum=*/0, maxSums, price, ans);
    return ans;
  }

 private:
  int maxSum(const vector<vector<int>>& tree, int u, int prev,
             vector<int>& maxSums, const vector<int>& price) {
    int maxChildSum = 0;
    for (const int v : tree[u])
      if (prev != v)
        maxChildSum = max(maxChildSum, maxSum(tree, v, u, maxSums, price));
    return maxSums[u] = price[u] + maxChildSum;
  }

  void reroot(const vector<vector<int>>& tree, int u, int prev, int parentSum,
              const vector<int>& maxSums, const vector<int>& price, int& ans) {
    // Get the top two subtree sums and the top one node index.
    int maxSubtreeSum1 = 0;
    int maxSubtreeSum2 = 0;
    int maxNode = -1;
    for (const int v : tree[u]) {
      if (v == prev)
        continue;
      if (maxSums[v] > maxSubtreeSum1) {
        maxSubtreeSum2 = maxSubtreeSum1;
        maxSubtreeSum1 = maxSums[v];
        maxNode = v;
      } else if (maxSums[v] > maxSubtreeSum2) {
        maxSubtreeSum2 = maxSums[v];
      }
    }

    if (tree[u].size() == 1)
      ans = max({ans, parentSum, maxSubtreeSum1});

    for (const int v : tree[u]) {
      if (v == prev)
        continue;
      const int nextParentSum =
          (v == maxNode ? price[u] + max(parentSum, maxSubtreeSum2)
                        : price[u] + max(parentSum, maxSubtreeSum1));
      reroot(tree, v, u, nextParentSum, maxSums, price, ans);
    }
  }
};
