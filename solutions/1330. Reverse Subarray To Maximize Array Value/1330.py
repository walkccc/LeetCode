class Solution:
  def maxValueAfterReverse(self, nums: List[int]) -> int:
    mini = math.inf
    maxi = -math.inf

    for a, b in zip(nums, nums[1:]):
      mini = min(mini, max(a, b))
      maxi = max(maxi, min(a, b))
    diff = max(0, (maxi - mini) * 2)

    for a, b in zip(nums, nums[1:]):
      headDiff = -abs(a - b) + abs(nums[0] - b)
      tailDiff = -abs(a - b) + abs(nums[-1] - a)
      diff = max(diff, headDiff, tailDiff)

    return sum(abs(a - b) for a, b in zip(nums, nums[1:])) + diff
