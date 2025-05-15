struct IndexedQuery {
  int queryIndex;
  int a;  // Alice's index
  int b;  // Bob's index
};

class Solution {
 public:
  // Similar to 2736. Maximum Sum Queries
  vector<int> leftmostBuildingQueries(vector<int>& heights,
                                      vector<vector<int>>& queries) {
    vector<int> ans(queries.size(), -1);
    // Store indices (heightsIndex) of heights with heights[heightsIndex] in
    // descending order.
    vector<int> stack;

    // Iterate through queries and heights simultaneously.
    int heightsIndex = heights.size() - 1;
    for (const auto& [queryIndex, a, b] : getIndexedQueries(queries)) {
      if (a == b || heights[a] < heights[b]) {
        // 1. Alice and Bob are already in the same index (a == b) or
        // 2. Alice can jump from a -> b (heights[a] < heights[b]).
        ans[queryIndex] = b;
      } else {
        // Now, a < b and heights[a] >= heights[b].
        // Gradually add heights with an index > b to the monotonic stack.
        while (heightsIndex > b) {
          // heights[heightsIndex] is a better candidate, given that
          // heightsIndex is smaller than the indices in the stack and
          // heights[heightsIndex] is larger or equal to the heights mapped in
          // the stack.
          while (!stack.empty() &&
                 heights[stack.back()] <= heights[heightsIndex])
            stack.pop_back();
          stack.push_back(heightsIndex--);
        }
        // Binary search to find the smallest index j such that j > b and
        // heights[j] > heights[a], thereby ensuring heights[j] > heights[b].
        if (const auto it = upper_bound(
                stack.rbegin(), stack.rend(), a,
                [&](int a, int b) { return heights[a] < heights[b]; });
            it != stack.rend())
          ans[queryIndex] = *it;
      }
    }

    return ans;
  }

 private:
  vector<IndexedQuery> getIndexedQueries(const vector<vector<int>>& queries) {
    vector<IndexedQuery> indexedQueries;
    for (int i = 0; i < queries.size(); ++i) {
      // Make sure that a <= b.
      const int a = min(queries[i][0], queries[i][1]);
      const int b = max(queries[i][0], queries[i][1]);
      indexedQueries.push_back({i, a, b});
    }
    ranges::sort(
        indexedQueries,
        [](const IndexedQuery& a, const IndexedQuery& b) { return a.b > b.b; });
    return indexedQueries;
  }
};
