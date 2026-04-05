class Solution:
  def maximumPossibleSize(self, nums: list[int]) -> int:
    ans = 0
    prev = 0

    for num in nums:
      if num >= prev:
        prev = num
        ans += 1

    return ans
