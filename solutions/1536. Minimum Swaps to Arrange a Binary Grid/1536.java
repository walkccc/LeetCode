class Solution {
  public int minSwaps(int[][] grid) {
    final int n = grid.length;
    int ans = 0;
    // suffixZeros[i] := the number of suffix zeros in the i-th row
    int[] suffixZeros = new int[n];

    for (int i = 0; i < grid.length; ++i)
      suffixZeros[i] = getSuffixZeroCount(grid[i]);

    for (int i = 0; i < n; ++i) {
      final int neededZeros = n - 1 - i;
      // Get the first row with suffix zeros >= `neededZeros` in suffixZeros[i:..n).
      final int j = getFirstRowWithEnoughZeros(suffixZeros, i, neededZeros);
      if (j == -1)
        return -1;
      // Move the rows[j] to the rows[i].
      for (int k = j; k > i; --k)
        suffixZeros[k] = suffixZeros[k - 1];
      ans += j - i;
    }

    return ans;
  }

  private int getSuffixZeroCount(int[] row) {
    for (int i = row.length - 1; i >= 0; --i)
      if (row[i] == 1)
        return row.length - i - 1;
    return row.length;
  }

  // Returns first row that has suffix zeros > `neededZeros` in suffixZeros[i:..n).
  private int getFirstRowWithEnoughZeros(int[] suffixZeros, int i, int neededZeros) {
    for (int j = i; j < suffixZeros.length; ++j)
      if (suffixZeros[j] >= neededZeros)
        return j;
    return -1;
  }
}
