class Solution {
  public String kthSmallestPath(int[] destination, int k) {
    StringBuilder sb = new StringBuilder();
    int v = destination[0];
    int h = destination[1];
    final int totalSteps = v + h;
    final int[][] comb = getComb(totalSteps - 1, v);

    for (int i = 0; i < totalSteps; ++i) {
      // If 'H' is picked, we can reach ranks [1, availableRank].
      final int availableRank = comb[h + v - 1][v];
      if (availableRank >= k) { // Should pick 'H'.
        sb.append('H');
        --h;
      } else { // Should pick 'V'.
        k -= availableRank;
        sb.append('V');
        --v;
      }
    }

    return sb.toString();
  }

  private int[][] getComb(int n, int k) {
    int[][] comb = new int[n + 1][k + 1];
    for (int i = 0; i <= n; ++i)
      comb[i][0] = 1;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= k; ++j)
        comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
    return comb;
  }
}
