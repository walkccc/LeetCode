class Solution {
  public int numSubmatrixSumTarget(int[][] matrix, int target) {
    int ans = 0;

    for (int[] row : matrix)
      for (int i = 1; i < row.length; ++i)
        row[i] += row[i - 1];

    for (int baseCol = 0; baseCol < matrix[0].length; ++baseCol)
      for (int j = baseCol; j < matrix[0].length; ++j) {
        Map<Integer, Integer> prefixSumCount = new HashMap<>();
        prefixSumCount.put(0, 1);
        int sum = 0;
        for (int i = 0; i < matrix.length; ++i) {
          if (baseCol > 0)
            sum -= matrix[i][baseCol - 1];
          sum += matrix[i][j];
          ans += prefixSumCount.getOrDefault(sum - target, 0);
          prefixSumCount.put(sum, prefixSumCount.getOrDefault(sum, 0) + 1);
        }
      }

    return ans;
  }
}