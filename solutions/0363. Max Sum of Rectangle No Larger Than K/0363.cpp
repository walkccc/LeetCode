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
        // find the max subarray no more than k
        set<int> accumulate{0};
        int prefixSum = 0;
        for (const int sum : sums) {
          prefixSum += sum;
          const auto it = accumulate.lower_bound(prefixSum - k);
          if (it != cend(accumulate))
            ans = max(ans, prefixSum - *it);
          accumulate.insert(prefixSum);
        }
      }
    }

    return ans;
  }
};