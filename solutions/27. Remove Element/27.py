class Solution:
  def removeElement(self, nums: list[int], val: int) -> int:
    i = 0

    for num in nums:
      if num != val:
        nums[i] = num
        i += 1

    return i
