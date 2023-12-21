class Solution {
  public int shortestWay(String source, String target) {
    final int m = source.length();
    final int n = target.length();
    // dp[i][c] := the earliest index >= i s.t. source[index] = c
    // dp[i][c] := -1 if c isn't in the source
    int[][] dp = new int[m][26];

    Arrays.stream(dp).forEach(A -> Arrays.fill(A, -1));

    dp[m - 1][source.charAt(m - 1) - 'a'] = m - 1;
    for (int i = m - 2; i >= 0; --i) {
      dp[i] = dp[i + 1].clone();
      dp[i][source.charAt(i) - 'a'] = i;
    }

    int ans = 0;
    int i = 0; // source's index

    for (final char c : target.toCharArray()) {
      if (dp[0][c - 'a'] == -1)
        return -1;
      // If there are no c's left in source that occur more than i times but
      // there are c's from earlier in the subsequence, add 1 to subsequence
      // count and reset source's index to 0.
      if (dp[i][c - 'a'] == -1) {
        ++ans;
        i = 0;
      }
      // Continue taking letters from the subsequence.
      i = dp[i][c - 'a'] + 1;
      if (i == m) {
        ++ans;
        i = 0;
      }
    }

    return ans + (i == 0 ? 0 : 1);
  }
}
