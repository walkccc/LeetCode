class Solution:
  def lastStoneWeightII(self, stones: list[int]) -> int:
    summ = sum(stones)
    s = 0
    dp = [True] + [False] * summ

    for stone in stones:
      for w in range(summ // 2 + 1)[::-1]:
        if w >= stone:
          dp[w] = dp[w] or dp[w - stone]
        if dp[w]:
          s = max(s, w)

    return summ - 2 * s
