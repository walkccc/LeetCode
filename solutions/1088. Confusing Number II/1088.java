class Solution {
  public int confusingNumberII(int n) {
    return dfs(n, 0, 0, 1);
  }

  private int[][] digitToRotated = {{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};

  int dfs(int n, long num, long rotatedNum, long unit) {
    int ans = num == rotatedNum ? 0 : 1;
    // add one more digit
    for (int[] pair : digitToRotated) {
      final int digit = pair[0];
      final int rotated = pair[1];
      if (digit == 0 && num == 0)
        continue;
      final long nextNum = num * 10 + digit;
      if (nextNum > n)
        break;
      ans += dfs(n, nextNum, rotated * unit + rotatedNum, unit * 10);
    }
    return ans;
  }
}
