class Solution:
  def findLength(self, A: List[int], B: List[int]) -> int:
    ans = 0
    dp = [0] * (len(B) + 1)

    for i, a in reversed(list(enumerate(A))):
      for j, b in enumerate(B):
        dp[j] = dp[j + 1] + 1 if a == b else 0
        ans = max(ans, dp[j])

    return ans
