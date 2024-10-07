class Solution:
  def countElements(self, nums: list[int]) -> int:
    mn = min(nums)
    mx = max(nums)
    return sum(mn < num < mx for num in nums)
