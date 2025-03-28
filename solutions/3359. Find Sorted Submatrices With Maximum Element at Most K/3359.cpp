
struct T {
  int subarrayWidth;
  int rowIndex;
  int accumulatedSubmatrices;
};

class Solution {
 public:
  long long countSubmatrices(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    long ans = 0;
    // dp[i][j] := the number of valid subarrays ending in grid[i][j]
    vector<vector<int>> dp(m, vector<int>(n));
    // stacks[j] := the stack of valid
    // (subarray width, row index, number of accumulated submatrices) ending in
    // column j
    vector<stack<T>> stacks(n);

    for (int j = 0; j < n; ++j)
      stacks[j].emplace(0, -1, 0);

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] > k) {
          stacks[j] = stack<T>();
          stacks[j].emplace(0, i, 0);
        } else {
          dp[i][j] = 1;
          if (j > 0 && grid[i][j - 1] <= k && grid[i][j - 1] >= grid[i][j])
            // Extend the valid subarrays to the current number.
            dp[i][j] += dp[i][j - 1];
          const int width = dp[i][j];
          stack<T>& stack = stacks[j];
          // Remove subarray widths greater than the current width since they
          // will become invalid.
          while (!stack.empty() && width < stack.top().subarrayWidth)
            stack.pop();
          const int height = i - stack.top().rowIndex;
          const int newSubmatrices = width * height;
          const int accumulatedSubmatrices =
              stack.top().accumulatedSubmatrices + newSubmatrices;
          ans += accumulatedSubmatrices;
          stack.emplace(width, i, accumulatedSubmatrices);
        }

    return ans;
  }
};
