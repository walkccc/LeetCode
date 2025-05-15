class Solution:
  def maximizeGreatness(self, nums: list[int]) -> int:
    ans = 0

    nums.sort()

    for num in nums:
      if num > nums[ans]:
        ans += 1

    return ans
