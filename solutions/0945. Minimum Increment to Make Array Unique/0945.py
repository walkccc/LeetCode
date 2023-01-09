class Solution:
  def minIncrementForUnique(self, A: List[int]) -> int:
    ans = 0
    minAvailable = 0

    A.sort()

    for a in A:
      ans += max(minAvailable - a, 0)
      minAvailable = max(minAvailable, a) + 1

    return ans
