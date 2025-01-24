class Solution:
  def nextPermutation(self, nums: list[int]) -> None:
    n = len(nums)

    # From back to front, find the first number < nums[i + 1].
    i = n - 2
    while i >= 0:
      if nums[i] < nums[i + 1]:
        break
      i -= 1

    # From back to front, find the first number > nums[i], swap it with nums[i].
    if i >= 0:
      for j in range(n - 1, i, -1):
        if nums[j] > nums[i]:
          nums[i], nums[j] = nums[j], nums[i]
          break

    def reverse(nums: list[int], l: int, r: int) -> None:
      while l < r:
        nums[l], nums[r] = nums[r], nums[l]
        l += 1
        r -= 1

    # Reverse nums[i + 1..n - 1].
    reverse(nums, i + 1, len(nums) - 1)
