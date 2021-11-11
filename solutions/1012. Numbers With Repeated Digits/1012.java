class Solution {
  public int numDupDigitsAtMostN(int N) {
    dfs(N, 0, 0);
    return N - uniqueNumbers + 1;
  }

  private int uniqueNumbers = 0;

  private void dfs(int N, int mask, long path) {
    if (path > N)
      return;

    ++uniqueNumbers;

    for (int digit = 0; digit < 10; ++digit) {
      if (mask == 0 && digit == 0)
        continue;
      if ((mask & (1 << digit)) > 0)
        continue;
      dfs(N, mask | (1 << digit), path * 10 + digit);
    }
  }
}
