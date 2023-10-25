class Solution:
  def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
    def ones(x):
      return bin(x).count('1')

    dp = [0] * (len(s) + 1)

    for i in range(1, len(s) + 1):
      dp[i] = dp[i - 1] ^ 1 << ord(s[i - 1]) - ord('a')

    return [
        ones(dp[right + 1] ^ dp[left]) // 2 <= k
        for left, right, k in queries
    ]
