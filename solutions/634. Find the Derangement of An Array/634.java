class Solution {
  public int findDerangement(int n) {
    int[] mem = new int[n + 1];
    return findDerangement(n, mem);
  }

  private static final int kMod = 1_000_000_007;

  private int findDerangement(int i, int[] mem) {
    if (i == 0)
      return 1;
    if (i == 1)
      return 0;
    if (mem[i] > 0)
      return mem[i];
    return mem[i] = (int) ((i - 1L) *
                           (findDerangement(i - 1, mem) + //
                            findDerangement(i - 2, mem)) %
                           kMod);
  }
}
