class Solution:
  def sortColors(self, nums: List[int]) -> None:
    zero = -1
    one = -1
    two = -1

    for num in nums:
      if num == 0:
        two += 1
        one += 1
        zero += 1
        nums[two] = 2
        nums[one] = 1
        nums[zero] = 0
      elif num == 1:
        two += 1
        one += 1
        nums[two] = 2
        nums[one] = 1
      else:
        two += 1
        nums[two] = 2
