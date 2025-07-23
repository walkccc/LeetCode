class Solution {
  public long countSubmatrices(int[][] grid, int k) {
    record T(int subarrayWidth, int rowIndex, int accumulatedSubmatrices) {}
    final int m = grid.length;
    final int n = grid[0].length;
    long ans = 0;
    // dp[i][j] := the number of valid subarrays ending in grid[i][j]
    int[][] dp = new int[m][n];
    // stacks[j] := the stack of valid
    // (subarray width, row index, number of accumulated submatrices) ending in
    // column j
    List<Deque<T>> stacks = new ArrayList<>(n);

    for (int j = 0; j < n; ++j) {
      Deque<T> stack = new ArrayDeque<>();
      stack.push(new T(0, -1, 0));
      stacks.add(stack);
    }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] > k) {
          stacks.get(j).clear();
          stacks.get(j).push(new T(0, i, 0));
        } else {
          dp[i][j] = 1;
          if (j > 0 && grid[i][j - 1] <= k && grid[i][j - 1] >= grid[i][j])
            // Extend the valid subarrays to the current number.
            dp[i][j] += dp[i][j - 1];
          final int width = dp[i][j];
          // Remove subarray widths greater than the current width since they
          // will become invalid.
          Deque<T> stack = stacks.get(j);
          while (!stack.isEmpty() && width < stack.peek().subarrayWidth)
            stack.pop();
          final int height = i - stack.peek().rowIndex;
          final int newSubmatrices = width * height;
          final int accumulatedSubmatrices = stack.peek().accumulatedSubmatrices + newSubmatrices;
          ans += accumulatedSubmatrices;
          stack.push(new T(width, i, accumulatedSubmatrices));
        }

    return ans;
  }
}
