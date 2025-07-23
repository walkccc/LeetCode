class Solution:
  def maxLength(self, nums: list[int]) -> int:
    n = len(nums)
    ans = 0

    for i in range(n):
      prod = 1
      l = 1
      g = 0
      for j in range(i, n):
        prod *= nums[j]
        l = math.lcm(l, nums[j])
        g = math.gcd(g, nums[j])
        if prod == l * g:
          ans = max(ans, j - i + 1)

    return ans
