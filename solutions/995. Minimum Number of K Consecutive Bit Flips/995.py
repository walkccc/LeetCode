class Solution:
  def minKBitFlips(self, nums: List[int], k: int) -> int:
    ans = 0
    flippedTime = 0

    for i, num in enumerate(nums):
      if i >= k and nums[i - k] == 2:
        flippedTime -= 1
      if flippedTime % 2 == num:
        if i + k > len(nums):
          return -1
        ans += 1
        flippedTime += 1
        nums[i] = 2

    return ans
