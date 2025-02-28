class Solution:
  def countSubstrings(self, s: str) -> int:
    ans = 0
    # dp[i][num][rem] := the number of first `i` digits of s that have a
    # remainder of `rem` when divided by `num`
    dp = [[[0] * 10 for _ in range(10)] for _ in range(len(s) + 1)]

    for i in range(1, len(s) + 1):
      digit = int(s[i - 1])
      for num in range(1, 10):
        for rem in range(num):
          dp[i][num][(rem * 10 + digit) % num] += dp[i - 1][num][rem]
        dp[i][num][digit % num] += 1
      ans += dp[i][digit][0]

    return ans
