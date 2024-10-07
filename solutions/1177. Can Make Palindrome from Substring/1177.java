class Solution {
  public List<Boolean> canMakePaliQueries(String s, int[][] queries) {
    List<Boolean> ans = new ArrayList<>();
    int[] dp = new int[s.length() + 1];

    for (int i = 1; i <= s.length(); ++i)
      dp[i] = dp[i - 1] ^ 1 << s.charAt(i - 1) - 'a';

    for (int[] query : queries) {
      int odds = Integer.bitCount(dp[query[1] + 1] ^ dp[query[0]]);
      ans.add(odds / 2 <= query[2]);
    }

    return ans;
  }
}
