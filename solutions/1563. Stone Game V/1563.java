class Solution {
  public int stoneGameV(int[] stoneValue) {
    final int n = stoneValue.length;
    int[][] mem = new int[n][n];
    int[] prefix = new int[n + 1];
    Arrays.stream(mem).forEach(A -> Arrays.fill(A, Integer.MIN_VALUE));
    for (int i = 0; i < n; ++i)
      prefix[i + 1] = prefix[i] + stoneValue[i];
    return stoneGameV(stoneValue, 0, n - 1, prefix, mem);
  }

  // Returns the maximum score that Alice can obtain from stoneValue[i..j].
  private int stoneGameV(int[] stoneValue, int i, int j, int[] prefix, int[][] mem) {
    if (i == j)
      return 0;
    if (mem[i][j] != Integer.MIN_VALUE)
      return mem[i][j];

    // Try all the possible partitions.
    for (int p = i; p < j; ++p) {
      // sum(stoneValue[i..p])
      final int leftSum = prefix[p + 1] - prefix[i];
      final int throwRight = leftSum + stoneGameV(stoneValue, i, p, prefix, mem);
      // sum(stoneValue[p + 1..j])
      final int rightSum = prefix[j + 1] - prefix[p + 1];
      final int throwLeft = rightSum + stoneGameV(stoneValue, p + 1, j, prefix, mem);
      if (leftSum < rightSum)
        mem[i][j] = Math.max(mem[i][j], throwRight);
      else if (leftSum > rightSum)
        mem[i][j] = Math.max(mem[i][j], throwLeft);
      else
        mem[i][j] = Math.max(Math.max(mem[i][j], throwLeft), throwRight);
    }

    return mem[i][j];
  }
}
