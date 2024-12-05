class Solution {
  public int twoEggDrop(int n) {
    return superEggDrop(2, n);
  }

  // Same as 887. Super Egg Drop
  private int superEggDrop(int k, int n) {
    int[][] mem = new int[k + 1][n + 1];
    Arrays.stream(mem).forEach(A -> Arrays.fill(A, -1));
    return drop(k, n, mem);
  }

  // Returns the minimum number of moves to know f with k eggs and n floors.
  private int drop(int k, int n, int[][] mem) {
    if (k == 0) // no eggs -> done
      return 0;
    if (k == 1) // one egg -> drop from 1-th floor to n-th floor
      return n;
    if (n == 0) // no floor -> done
      return 0;
    if (n == 1) // one floor -> drop from that floor
      return 1;
    if (mem[k][n] != -1)
      return mem[k][n];

    int l = 1;
    int r = n + 1;

    while (l < r) {
      final int m = (l + r) / 2;
      final int broken = drop(k - 1, m - 1, mem);
      final int unbroken = drop(k, n - m, mem);
      if (broken >= unbroken)
        r = m;
      else
        l = m + 1;
    }

    return mem[k][n] = 1 + drop(k - 1, l - 1, mem);
  }
}
