class Solution:
  def countElements(self, nums: List[int]) -> int:
    mn = min(nums)
    mx = max(nums)
    return sum(mn < num < mx for num in nums)
