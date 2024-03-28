class Solution:
  def findLongestChain(self, pairs: List[List[int]]) -> int:
    ans = 0
    prevEnd = -math.inf

    for s, e in sorted(pairs, key=lambda x: x[1]):
      if s > prevEnd:
        ans += 1
        prevEnd = e

    return ans
