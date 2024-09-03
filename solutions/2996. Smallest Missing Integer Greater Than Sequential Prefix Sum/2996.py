class Solution:
  def missingInteger(self, nums: list[int]) -> int:
    numsSet = set(nums)
    ans = nums[0]

    for i in range(1, len(nums)):
      if nums[i] != nums[i - 1] + 1:
        break
      ans += nums[i]

    while ans in numsSet:
      ans += 1

    return ans
