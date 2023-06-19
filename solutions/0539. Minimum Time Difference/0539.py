class Solution:
  def findMinDifference(self, timePoints: List[str]) -> int:
    ans = 24 * 60
    nums = sorted([int(timePoint[:2]) * 60 + int(timePoint[3:])
                   for timePoint in timePoints])

    for a, b in zip(nums, nums[1:]):
      ans = min(ans, b - a)

    return min(ans, 24 * 60 - nums[-1] + nums[0])
