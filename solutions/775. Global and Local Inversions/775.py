class Solution:
  def isIdealPermutation(self, nums: list[int]) -> bool:
    mx = -1  # the number that is most likely > nums[i + 2]

    for i in range(len(nums) - 2):
      mx = max(mx, nums[i])
      if mx > nums[i + 2]:
        return False

    return True
