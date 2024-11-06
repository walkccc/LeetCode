class Solution:
  def minOperations(self, nums: list[int]) -> int:
    ans = 0
    target = 1

    for num in nums:
      if num != target:
        ans += 1
        target ^= 1

    return ans
