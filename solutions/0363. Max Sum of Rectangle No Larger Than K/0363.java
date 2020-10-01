class Solution {
  public int maxSumSubmatrix(int[][] matrix, int k) {
    final int m = matrix.length;
    final int n = matrix[0].length;

    int ans = Integer.MIN_VALUE;

    for (int baseCol = 0; baseCol < n; ++baseCol) {
      // sums[i] := sum(matrix[i][baseCol..j])
      int[] sums = new int[m];
      for (int j = baseCol; j < n; ++j) {
        for (int i = 0; i < m; ++i)
          sums[i] += matrix[i][j];
        // find the max subarray no more than k
        TreeSet<Integer> accumulate = new TreeSet<>(Arrays.asList(0));
        int prefixSum = 0;
        for (final int sum : sums) {
          prefixSum += sum;
          final Integer lo = accumulate.ceiling(prefixSum - k);
          if (lo != null)
            ans = Math.max(ans, prefixSum - lo);
          accumulate.add(prefixSum);
        }
      }
    }

    return ans;
  }
}