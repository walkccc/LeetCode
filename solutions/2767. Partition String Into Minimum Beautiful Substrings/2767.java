class Solution {
  public int minimumBeautifulSubstrings(String s) {
    final int n = s.length();
    // dp[i] := the minimum number of beautiful substrings for the first i chars
    int[] dp = new int[n + 1];
    Arrays.fill(dp, n + 1);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
      if (s.charAt(i - 1) == '0')
        continue;
      int num = 0; // num of s[i - 1..j - 1]
      for (int j = i; j <= n; ++j) {
        num = (num << 1) + s.charAt(j - 1) - '0';
        if (isPowerOfFive(num))
          dp[j] = Math.min(dp[j], dp[i - 1] + 1);
      }
    }

    return dp[n] == n + 1 ? -1 : dp[n];
  }

  private boolean isPowerOfFive(int num) {
    while (num % 5 == 0)
      num /= 5;
    return num == 1;
  }
}
