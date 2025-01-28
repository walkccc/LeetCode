class Solution:
  def minSwaps(self, nums: list[int]) -> int:
    n = len(nums)
    k = nums.count(1)
    ones = 0  # the number of ones in the window
    maxOnes = 0  # the maximum number of ones in the window

    for i in range(n * 2):
      if i >= k and nums[i % n - k]:  # Magic in Python :)
        ones -= 1
      if nums[i % n]:
        ones += 1
      maxOnes = max(maxOnes, ones)

    return k - maxOnes
