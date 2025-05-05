class Solution:
  def uniqueXorTriplets(self, nums: list[int]) -> int:
    n = len(nums)
    if n < 3:
      return n
    return 1 << (int(math.log2(n)) + 1)
