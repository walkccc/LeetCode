class Solution {
  public int superEggDrop(int k, int n) {
    int[][] mem = new int[k + 1][n + 1];
    Arrays.stream(mem).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));
    return drop(k, n, mem);
  }

  // Returns the minimum number of moves to know f with k eggs and n floors.
  private int drop(int k, int n, int[][] mem) {
    if (k == 0) // no eggs -> done
      return 0;
    if (k == 1) // one egg -> drop from 1st floor to nth floor
      return n;
    if (n == 0) // no floor -> done
      return 0;
    if (n == 1) // one floor -> drop from that floor
      return 1;
    if (mem[k][n] != Integer.MAX_VALUE)
      return mem[k][n];

    for (int i = 1; i <= n; ++i) {
      final int broken = drop(k - 1, i - 1, mem);
      final int unbroken = drop(k, n - i, mem);
      mem[k][n] = Math.min(mem[k][n], 1 + Math.max(broken, unbroken));
    }

    return mem[k][n];
  }
}
