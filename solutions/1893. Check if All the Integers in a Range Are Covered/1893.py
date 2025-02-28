class Solution:
  def isCovered(self, ranges: list[list[int]], left: int, right: int) -> bool:
    return all(any(l <= i <= r for l, r in ranges) for i in range(
        left, right + 1))
