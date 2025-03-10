class Solution:
  def addRungs(self, rungs: list[int], dist: int) -> int:
    ans = 0
    prev = 0

    for rung in rungs:
      ans += (rung - prev - 1) // dist
      prev = rung

    return ans
