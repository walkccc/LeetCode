class Solution:
  def minOperations(self, nums: list[int], k: int) -> int:
    return sum(num < k for num in nums)
