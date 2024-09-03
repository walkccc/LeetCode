from sortedcontainers import SortedSet


class Solution:
  def minAbsoluteDifference(self, nums: list[int], x: int) -> int:
    ans = math.inf
    seen = SortedSet()

    for i in range(x, len(nums)):
      seen.add(nums[i - x])
      it = seen.bisect_left(nums[i])
      if it != len(seen):
        ans = min(ans, seen[it] - nums[i])
      if it != 0:
        ans = min(ans, nums[i] - seen[it - 1])

    return ans
