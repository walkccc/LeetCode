class Solution:
  def findKOr(self, nums: list[int], k: int) -> int:
    MAX_BIT = 30
    return sum(2**i
               for i in range(MAX_BIT + 1)
               if sum(num >> i & 1 for num in nums) >= k)
