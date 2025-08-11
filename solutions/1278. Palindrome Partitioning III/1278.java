class Solution {
  public int palindromePartition(String s, int k) {
    final int n = s.length();
    int[][] mem = new int[n + 1][k + 1];
    // cost[i][j] := the minimum cost to make s[i..j] palindrome
    int[][] cost = new int[n][n];

    Arrays.stream(mem).forEach(A -> Arrays.fill(A, n));

    for (int d = 1; d < n; ++d)
      for (int i = 0, j = d; j < n; ++i, ++j)
        cost[i][j] = (s.charAt(i) == s.charAt(j) ? 0 : 1) + cost[i + 1][j - 1];

    return palindromePartition(n, k, cost, mem);
  }

  // Returns the minimum cost to make k palindromes by s[0..i).
  private int palindromePartition(int n, int k, int[][] cost, int[][] mem) {
    if (k == 1)
      return cost[0][n - 1];
    if (mem[n][k] < n)
      return mem[n][k];

    // Try all the possible partitions.
    for (int i = k - 1; i < n; ++i)
      mem[n][k] = Math.min(mem[n][k], //
                           palindromePartition(i, k - 1, cost, mem) + cost[i][n - 1]);

    return mem[n][k];
  }
}
