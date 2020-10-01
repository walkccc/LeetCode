class Solution {
 public:
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int ans = 0;

    for (vector<int>& row : matrix)
      for (int i = 1; i < row.size(); ++i) row[i] += row[i - 1];

    for (int baseCol = 0; baseCol < matrix[0].size(); ++baseCol)
      for (int j = baseCol; j < matrix[0].size(); ++j) {
        unordered_map<int, int> prefixSumCount{{0, 1}};
        int sum = 0;
        for (int i = 0; i < matrix.size(); ++i) {
          if (baseCol > 0) sum -= matrix[i][baseCol - 1];
          sum += matrix[i][j];
          if (prefixSumCount.count(sum - target))
            ans += prefixSumCount[sum - target];
          ++prefixSumCount[sum];
        }
      }

    return ans;
  }
};