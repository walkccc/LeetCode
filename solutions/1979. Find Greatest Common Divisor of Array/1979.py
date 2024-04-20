class Solution:
  def findGCD(self, nums: List[int]) -> int:
    return math.gcd(min(nums), max(nums))
