class Solution:
  def findPermutation(self, nums: list[int]) -> list[int]:
    n = len(nums)
    bestPick = [[0] * (1 << n) for _ in range(n)]

    @functools.lru_cache(None)
    def getScore(last: int, mask: int) -> int:
      if mask.bit_count() == len(nums):
        return abs(last - nums[0])

      minScore = math.inf
      for i in range(1, len(nums)):
        if mask >> i & 1:
          continue
        nextMinScore = abs(last - nums[i]) + getScore(i, mask | (1 << i))
        if nextMinScore < minScore:
          minScore = nextMinScore
          bestPick[last][mask] = i

      return minScore

    getScore(0, 1)
    return self._construct(bestPick)

  def _construct(self, bestPick: list[list[int]]) -> list[int]:
    ans = []
    last = 0
    mask = 1
    for _ in range(len(bestPick)):
      ans.append(last)
      last = bestPick[last][mask]
      mask |= 1 << last
    return ans
