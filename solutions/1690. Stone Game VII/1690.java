class Solution {
  public int stoneGameVII(int[] stones) {
    final int n = stones.length;
    Integer[][] mem = new Integer[n][n];
    int[] prefix = new int[n + 1];
    for (int i = 0; i < n; ++i)
      prefix[i + 1] = prefix[i] + stones[i];
    return stoneGameVII(stones, 0, n - 1, prefix, mem);
  }

  // Returns the maximum score you can get more than your opponent in
  // stones[i..j].
  private int stoneGameVII(int[] stones, int i, int j, int[] prefix, Integer[][] mem) {
    if (i == j)
      return 0;
    if (mem[i][j] != null)
      return mem[i][j];
    // Remove stones[i] to get sum(stones[i + 1..j]).
    final int removeLeft = prefix[j + 1] - prefix[i + 1] - //
                           stoneGameVII(stones, i + 1, j, prefix, mem);

    // Remove stones[j] to get sum(stones[i..j - 1]).
    final int removeRight = prefix[j] - prefix[i] - //
                            stoneGameVII(stones, i, j - 1, prefix, mem);
    return mem[i][j] = Math.max(removeLeft, removeRight);
  }
}
