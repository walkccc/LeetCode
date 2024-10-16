class Solution {
  public int minCost(int n, int[] cuts) {
    int[] extendedCuts = new int[cuts.length + 2];
    int[][] mem = new int[extendedCuts.length][extendedCuts.length];
    System.arraycopy(cuts, 0, extendedCuts, 1, cuts.length);
    extendedCuts[0] = 0;
    extendedCuts[extendedCuts.length - 1] = n;
    Arrays.sort(extendedCuts);
    Arrays.stream(mem).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));
    return minCost(extendedCuts, 0, extendedCuts.length - 1, mem);
  }

  // Returns minCost(cuts[i..j]).
  private int minCost(int[] cuts, int i, int j, int[][] mem) {
    if (j - i <= 1)
      return 0;
    if (mem[i][j] != Integer.MAX_VALUE)
      return mem[i][j];

    for (int k = i + 1; k < j; ++k)
      mem[i][j] = Math.min(mem[i][j],
                           cuts[j] - cuts[i] + minCost(cuts, i, k, mem) + minCost(cuts, k, j, mem));

    return mem[i][j];
  }
}
