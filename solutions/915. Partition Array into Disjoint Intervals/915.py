class Solution:
  def partitionDisjoint(self, nums: List[int]) -> int:
    n = len(nums)
    mini = [0] * (n - 1) + [nums[-1]]
    maxi = -math.inf

    for i in range(n - 2, - 1, -1):
      mini[i] = min(mini[i + 1], nums[i])

    for i, num in enumerate(nums):
      maxi = max(maxi, num)
      if maxi <= mini[i + 1]:
        return i + 1
