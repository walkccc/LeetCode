class Solution:
  def xorGame(self, nums: List[int]) -> bool:
    xors = 0

    for num in nums:
      xors ^= num

    return xors == 0 or len(nums) % 2 == 0
