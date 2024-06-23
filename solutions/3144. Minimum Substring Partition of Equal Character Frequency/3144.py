class Solution:
  def minimumSubstringsInPartition(self, s: str) -> int:
    n = len(s)
    # dp[i] := the minimum number of substrings in s[0..i]
    dp = [n] * n

    for i in range(n):
      count = collections.Counter()
      for j in range(i, -1, -1):
        count[s[j]] += 1
        # word[j..i] is balanced.
        if min(count.values()) == max(count.values()):
          dp[i] = min(dp[i], 1 + dp[j - 1] if j > 0 else 1)

    return dp[-1]
