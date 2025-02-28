class Solution:
  def minimumSplits(self, nums: list[int]) -> int:
    ans = 1
    gcd = nums[0]

    for num in nums:
      newGcd = math.gcd(gcd, num)
      if newGcd > 1:
        gcd = newGcd
      else:
        gcd = num
        ans += 1

    return ans
