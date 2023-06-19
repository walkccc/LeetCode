class Solution:
  def stoneGameIX(self, stones: List[int]) -> bool:
    count = collections.Counter(stone % 3 for stone in stones)
    if count[0] % 2 == 0:
      return min(count[1], count[2]) > 0
    return abs(count[1] - count[2]) > 2
