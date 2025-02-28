class Solution:
  def findFinalValue(self, nums: list[int], original: int) -> int:
    seen = [False] * 1001

    for num in nums:
      seen[num] = True

    while original < 1001 and seen[original]:
      original *= 2

    return original
