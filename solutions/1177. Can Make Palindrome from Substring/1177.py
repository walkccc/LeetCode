class Solution:
  def canMakePaliQueries(self, s: str, queries: list[list[int]]) -> list[bool]:
    dp = [0] * (len(s) + 1)

    for i in range(1, len(s) + 1):
      dp[i] = dp[i - 1] ^ 1 << ord(s[i - 1]) - ord('a')

    return [
        (dp[right + 1] ^ dp[left]).bit_count() // 2 <= k
        for left, right, k in queries
    ]
