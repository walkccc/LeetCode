class Solution:
  def maxValueAfterReverse(self, nums: list[int]) -> int:
    mn = math.inf
    mx = -math.inf

    for a, b in zip(nums, nums[1:]):
      mn = min(mn, max(a, b))
      mx = max(mx, min(a, b))
    diff = max(0, (mx - mn) * 2)

    for a, b in zip(nums, nums[1:]):
      headDiff = -abs(a - b) + abs(nums[0] - b)
      tailDiff = -abs(a - b) + abs(nums[-1] - a)
      diff = max(diff, headDiff, tailDiff)

    return sum(abs(a - b) for a, b in zip(nums, nums[1:])) + diff
