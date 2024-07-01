class Solution {
  public int numberOfSets(int n, int k) {
    Integer[][][] mem = new Integer[n][k + 1][2];
    return numberOfSets(0, k, /*drawing=*/false, n, mem);
  }

  private static final int kMod = 1_000_000_007;

  private int numberOfSets(int i, int k, boolean drawing, int n, Integer[][][] mem) {
    if (k == 0) // Find a way to draw k segments.
      return 1;
    if (i == n) // Reach the end.
      return 0;
    if (mem[i][k][drawing ? 1 : 0] != null)
      return mem[i][k][drawing ? 1 : 0];
    if (drawing)
      // 1. Keep drawing at i and move to i + 1.
      // 2. Stop at i so decrease k. We can start from i for the next segment.
      return mem[i][k][drawing ? 1 : 0] = (numberOfSets(i + 1, k, true, n, mem) + //
                                           numberOfSets(i, k - 1, false, n, mem)) %
                                          kMod;
    // 1. Skip i and move to i + 1.
    // 2. Start at i and move to i + 1.
    return mem[i][k][drawing ? 1 : 0] = (numberOfSets(i + 1, k, false, n, mem) + //
                                         numberOfSets(i + 1, k, true, n, mem)) %
                                        kMod;
  }
}
