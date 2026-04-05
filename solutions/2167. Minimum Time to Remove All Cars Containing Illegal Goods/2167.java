class Solution {
  public int minimumTime(String s) {
    final int n = s.length();
    // left[i] := the minimum time to remove the illegal cars of s[0..i]
    int[] left = new int[n];
    left[0] = s.charAt(0) - '0';
    // dp[i] := the minimum time to remove the illegal cars of s[0..i] optimally
    // + the time to remove the illegal cars of s[i + 1..n) consecutively
    // Note that the way to remove the illegal cars in the right part
    // doesn't need to be optimal since:
    //   `left | illegal cars | n - 1 - k` will be covered in
    //   `left' | n - 1 - i` later.
    int[] dp = new int[n];
    Arrays.fill(dp, n);
    dp[0] = left[0] + n - 1;

    for (int i = 1; i < n; ++i) {
      left[i] = Math.min(left[i - 1] + (s.charAt(i) - '0') * 2, i + 1);
      dp[i] = Math.min(dp[i], left[i] + n - 1 - i);
    }

    return Arrays.stream(dp).min().getAsInt();
  }
}
