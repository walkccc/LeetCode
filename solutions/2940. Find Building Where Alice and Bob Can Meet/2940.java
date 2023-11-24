class Solution {
  // Similar to 2736. Maximum Sum Queries
  public int[] leftmostBuildingQueries(int[] heights, int[][] queries) {
    IndexAndQuery[] indexAndQueries = getIndexAndQueries(queries);
    int[] ans = new int[queries.length];
    Arrays.fill(ans, -1);
    // Store indices (heightsIndex) of heights with heights[heightsIndex] in
    // descending order.
    List<Integer> stack = new ArrayList<>();

    // Iterate through queries and heights simultaneously.
    int heightsIndex = heights.length - 1;
    for (IndexAndQuery indexAndQuery : indexAndQueries) {
      final int i = indexAndQuery.i;
      final int a = indexAndQuery.a;
      final int b = indexAndQuery.b;
      if (a == b || heights[a] < heights[b]) {
        // (1) Alice and Bob are already in the same index (a == b) or
        // (2) Alice can jump from a -> b (heights[a] < heights[b]).
        ans[i] = b;
      } else {
        // Now, a < b and heights[a] >= heights[b].
        // Gradually add heights with an index > b to the monotonic stack.
        while (heightsIndex > b) {
          // heights[heightsIndex] is a better candidate, given that
          // heightsIndex is smaller than the indices in the stack and
          // heights[heightsIndex] is larger or equal to the heights mapped in
          // the stack.
          while (!stack.isEmpty() && heights[stack.get(stack.size() - 1)] <= heights[heightsIndex])
            stack.remove(stack.size() - 1);
          stack.add(heightsIndex--);
        }
        // Binary search to find the smallest index j such that j > b and
        // heights[j] > heights[a], thereby ensuring heights[t] > heights[b].
        final int j = lastGreater(stack, a, heights);
        if (j != -1)
          ans[i] = stack.get(j);
      }
    }

    return ans;
  }

  private record IndexAndQuery(int i, int a, int b){};

  // Returns the last index i in A s.t. heights[A.get(i)] is > heights[target].
  private int lastGreater(List<Integer> A, int target, int[] heights) {
    int l = -1;
    int r = A.size() - 1;
    while (l < r) {
      final int m = (l + r + 1) / 2;
      if (heights[A.get(m)] > heights[target])
        l = m;
      else
        r = m - 1;
    }
    return l;
  }

  private IndexAndQuery[] getIndexAndQueries(int[][] queries) {
    IndexAndQuery[] indexAndQueries = new IndexAndQuery[queries.length];
    for (int i = 0; i < queries.length; ++i) {
      // Make sure that a <= b.
      final int a = Math.min(queries[i][0], queries[i][1]);
      final int b = Math.max(queries[i][0], queries[i][1]);
      indexAndQueries[i] = new IndexAndQuery(i, a, b);
    }
    Arrays.sort(indexAndQueries, (a, b) -> b.b - a.b);
    return indexAndQueries;
  }
}
