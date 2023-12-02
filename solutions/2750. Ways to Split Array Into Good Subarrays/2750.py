class Solution:
  def numberOfGoodSubarraySplits(self, nums: List[int]) -> int:
    if 1 not in nums:
      return 0

    kMod = 1_000_000_007
    prev = -1  # the previous index of 1
    ans = 1

    for i, num in enumerate(nums):
      if num == 1:
        if prev != -1:
          ans *= i - prev
          ans %= kMod
        prev = i

    return ans
