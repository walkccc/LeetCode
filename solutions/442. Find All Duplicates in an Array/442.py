class Solution:
  def findDuplicates(self, nums: List[int]) -> List[int]:
    ans = []

    for num in nums:
      nums[abs(num) - 1] *= -1
      if nums[abs(num) - 1] > 0:
        ans.append(abs(num))

    return ans
