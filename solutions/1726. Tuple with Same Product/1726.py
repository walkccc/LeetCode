class Solution:
  def tupleSameProduct(self, nums: list[int]) -> int:
    # nums of ways to arrange (a, b) = 2
    # nums of ways to arrange (c, d) = 2
    # nums of ways to arrange (a, b), (c, d) = 2^3 = 8
    ans = 0
    count = collections.Counter()

    for i in range(len(nums)):
      for j in range(i):
        prod = nums[i] * nums[j]
        ans += count[prod] * 8
        count[prod] += 1

    return ans
