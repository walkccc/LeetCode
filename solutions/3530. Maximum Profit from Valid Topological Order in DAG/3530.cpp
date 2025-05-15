class Solution {
 public:
  int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
    const int maxMask = 1 << n;
    // need[i] := the bitmask representing all nodes that must be placed before
    // node i
    vector<int> need(n);
    // dp[mask] := the maximum profit achievable by placing the set of nodes
    // represented by `mask`
    vector<int> dp(maxMask, -1);
    dp[0] = 0;

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      need[v] |= 1 << u;
    }

    // Iterate over all subsets of nodes (represented by bitmask `mask`)
    for (unsigned mask = 0; mask < maxMask; ++mask) {
      if (dp[mask] == -1)
        continue;
      // Determine the position of the next node to be placed (1-based).
      const int pos = popcount(mask) + 1;
      // Try to place each node `i` that hasn't been placed yet.
      for (int i = 0; i < n; ++i) {
        if (mask >> i & 1)
          continue;
        // Check if all dependencies of node `i` are already placed.
        if ((mask & need[i]) == need[i]) {
          const int newMask = mask | 1 << i;  // Mark node `i` as placed.
          dp[newMask] = max(dp[newMask], dp[mask] + score[i] * pos);
        }
      }
    }

    return dp.back();
  }
};
