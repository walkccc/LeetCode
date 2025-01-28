class Solution {
 public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    int ans = INT_MIN;

    for (int baseCol = 0; baseCol < n; ++baseCol) {
      // sums[i] := sum(matrix[i][baseCol..j])
      vector<int> sums(m, 0);
      for (int j = baseCol; j < n; ++j) {
        for (int i = 0; i < m; ++i)
          sums[i] += matrix[i][j];
        // Find the maximum sum <= k of all the subarrays.
        set<int> accumulate{0};
        int prefix = 0;
        for (const int sum : sums) {
          prefix += sum;
          if (const auto it = accumulate.lower_bound(prefix - k);
              it != accumulate.cend())
            ans = max(ans, prefix - *it);
          accumulate.insert(prefix);
        }
      }
    }

    return ans;
  }
};
