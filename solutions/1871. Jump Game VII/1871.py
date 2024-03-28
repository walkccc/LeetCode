class Solution:
  def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
    count = 0
    dp = [True] + [False] * (len(s) - 1)

    for i in range(minJump, len(s)):
      count += dp[i - minJump]
      if i - maxJump > 0:
        count -= dp[i - maxJump - 1]
      dp[i] = count and s[i] == '0'

    return dp[-1]
