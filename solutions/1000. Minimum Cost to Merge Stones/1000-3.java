class Solution {
  public int mergeStones(int[] stones, int k) {
    final int n = stones.length;
    if ((n - 1) % (k - 1) != 0)
      return -1;

    int[][] mem = new int[n][n];
    int[] prefix = new int[n + 1];

    Arrays.stream(mem).forEach(A -> Arrays.fill(A, kMax));

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = prefix[i] + stones[i];

    final int cost = mergeStones(stones, 0, n - 1, k, prefix, mem);
    return cost == kMax ? -1 : cost;
  }

  private static final int kMax = 1_000_000_000;

  // Returns the minimum cost to merge stones[i..j].
  private int mergeStones(final int[] stones, int i, int j, int k, int[] prefix, int[][] mem) {
    if (j - i + 1 < k)
      return 0;
    if (mem[i][j] != kMax)
      return mem[i][j];

    for (int m = i; m < j; m += k - 1)
      mem[i][j] = Math.min(mem[i][j], mergeStones(stones, i, m, k, prefix, mem) +
                                          mergeStones(stones, m + 1, j, k, prefix, mem));
    if ((j - i) % (k - 1) == 0)
      mem[i][j] += prefix[j + 1] - prefix[i];

    return mem[i][j];
  }
}
