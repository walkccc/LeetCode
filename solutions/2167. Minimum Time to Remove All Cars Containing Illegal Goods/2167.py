class Solution:
  def minimumTime(self, s: str) -> int:
    n = len(s)
    # left[i] := min time to remove illegal cars of s[0..i]
    left = [0] * n
    left[0] = ord(s[0]) - ord('0')
    # dp[i] := min time to remove illegal cars of s[0..i] in optimal fashion +
    #              time to remove illegal cars of s[i + 1..n - 1] consecutively
    # Note the way to remove illegal cars in the right part doesn't need to be
    # optimal since: `left | illegal cars | n - 1 - k` will be covered in
    #                `left' | n - 1 - i` later
    dp = [n] * n
    dp[0] = left[0] + n - 1

    for i in range(1, n):
      left[i] = min(left[i - 1] + (ord(s[i]) - ord('0')) * 2, i + 1)
      dp[i] = min(dp[i], left[i] + n - 1 - i)

    return min(dp)
