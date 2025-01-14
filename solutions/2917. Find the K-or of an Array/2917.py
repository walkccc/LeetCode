class Solution:
  def findKOr(self, nums: list[int], k: int) -> int:
    kMaxBit = 30
    return sum(2**i
               for i in range(kMaxBit + 1)
               if sum(num >> i & 1 for num in nums) >= k)
