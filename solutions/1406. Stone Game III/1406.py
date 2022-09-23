class Solution:
  def stoneGameIII(self, stoneValue: List[int]) -> str:
    # max "relative score" Alice can make w/ stoneValue[i:]
    @functools.lru_cache(None)
    def dp(i: int) -> int:
      if i == len(stoneValue):
        return 0

      res = -math.inf
      summ = 0

      for j in range(i, i + 3):
        if j == len(stoneValue):
          break
        summ += stoneValue[j]
        res = max(res, summ - dp(j + 1))

      return res

    score = dp(0)
    if score == 0:
      return 'Tie'
    return 'Alice' if score > 0 else 'Bob'
