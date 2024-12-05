class Solution:
  def findDuplicates(self, nums: list[int]) -> list[int]:
    ans = []

    for num in nums:
      nums[abs(num) - 1] *= -1
      if nums[abs(num) - 1] > 0:
        ans.append(abs(num))

    return ans
