class Solution:
  def decompressRLElist(self, nums: list[int]) -> list[int]:
    ans = []

    for i in range(0, len(nums), 2):
      ans += [nums[i + 1]] * nums[i]

    return ans
