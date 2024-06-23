class Solution:
  def isIdealPermutation(self, nums: List[int]) -> bool:
    maxi = -1  # the number that is most likely > nums[i + 2]

    for i in range(len(nums) - 2):
      maxi = max(maxi, nums[i])
      if maxi > nums[i + 2]:
        return False

    return True
