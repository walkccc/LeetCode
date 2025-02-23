class Solution:
  def partitionDisjoint(self, nums: list[int]) -> int:
    n = len(nums)
    mn = [0] * (n - 1) + [nums[-1]]
    mx = -math.inf

    for i in range(n - 2, - 1, -1):
      mn[i] = min(mn[i + 1], nums[i])

    for i, num in enumerate(nums):
      mx = max(mx, num)
      if mx <= mn[i + 1]:
        return i + 1
