class Solution:
  def largestInteger(self, nums: list[int], k: int) -> int:
    if k == len(nums):
      return max(nums)
    count = collections.Counter(nums)
    if k == 1:
      return max([num for num in nums if count[num] == 1], default=-1)
    return max(
        nums[0] if count[nums[0]] == 1 else -1,
        nums[-1] if count[nums[-1]] == 1 else -1
    )
