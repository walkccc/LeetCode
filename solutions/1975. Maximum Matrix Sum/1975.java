class Solution {
  public long maxMatrixSum(int[][] matrix) {
    long absSum = 0;
    int minAbs = Integer.MAX_VALUE;
    // 0 := even number of negatives
    // 1 := odd number of negatives
    int oddNeg = 0;

    for (int[] row : matrix)
      for (final int num : row) {
        absSum += Math.abs(num);
        minAbs = Math.min(minAbs, Math.abs(num));
        if (num < 0)
          oddNeg ^= 1;
      }

    return absSum - oddNeg * minAbs * 2;
  }
}
