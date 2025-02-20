class Solution:
  def minimumTime(self, s: str) -> int:
    n = len(s)
    # left[i] := the minimum time to remove the illegal cars of s[0..i]
    left = [0] * n
    left[0] = int(s[0])
    # dp[i] := the minimum time to remove the illegal cars of s[0..i] optimally
    # + the time to remove the illegal cars of s[i + 1..n) consecutively
    # Note that the way to remove the illegal cars in the right part
    # doesn't need to be optimal since:
    #   `left | illegal cars | n - 1 - k` will be covered in
    #   `left' | n - 1 - i` later.
    dp = [n] * n
    dp[0] = left[0] + n - 1

    for i in range(1, n):
      left[i] = min(left[i - 1] + int(s[i]) * 2, i + 1)
      dp[i] = min(dp[i], left[i] + n - 1 - i)

    return min(dp)
