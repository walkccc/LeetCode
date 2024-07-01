class Solution:
  def countPairs(self, coordinates: List[List[int]], k: int) -> int:
    ans = 0

    for x in range(k + 1):
      y = k - x
      count = collections.Counter()
      for xi, yi in coordinates:
        ans += count[(xi ^ x, yi ^ y)]
        count[(xi, yi)] += 1

    return ans
