class Solution {
  public int mergeStones(int[] stones, int K) {
    final int n = stones.length;
    int[][][] mem = new int[n][n][K + 1];
    int[] prefix = new int[n + 1];

    Arrays.stream(mem).forEach(A -> Arrays.stream(A).forEach(B -> Arrays.fill(B, MAX)));

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = prefix[i] + stones[i];

    final int cost = mergeStones(stones, 0, n - 1, 1, K, prefix, mem);
    return cost == MAX ? -1 : cost;
  }

  private static final int MAX = 1_000_000_000;

  // Returns the minimum cost to merge stones[i..j] into k piles.
  private int mergeStones(final int[] stones, int i, int j, int k, int K, int[] prefix,
                          int[][][] mem) {
    if ((j - i + 1 - k) % (K - 1) != 0)
      return MAX;
    if (i == j)
      return k == 1 ? 0 : MAX;
    if (mem[i][j][k] != MAX)
      return mem[i][j][k];
    if (k == 1)
      return mem[i][j][k] =
                 mergeStones(stones, i, j, K, K, prefix, mem) + prefix[j + 1] - prefix[i];

    for (int m = i; m < j; m += K - 1)
      mem[i][j][k] =
          Math.min(mem[i][j][k], mergeStones(stones, i, m, 1, K, prefix, mem) +
                                     mergeStones(stones, m + 1, j, k - 1, K, prefix, mem));

    return mem[i][j][k];
  }
}
