class Solution {
  public boolean canReach(String s, int minJump, int maxJump) {
    int count = 0;
    boolean dp[] = new boolean[s.length()];
    dp[0] = true;

    for (int i = minJump; i < s.length(); ++i) {
      count += dp[i - minJump] ? 1 : 0;
      if (i - maxJump > 0)
        count -= dp[i - maxJump - 1] ? 1 : 0;
      dp[i] = count > 0 && s.charAt(i) == '0';
    }

    return dp[dp.length - 1];
  }
}
