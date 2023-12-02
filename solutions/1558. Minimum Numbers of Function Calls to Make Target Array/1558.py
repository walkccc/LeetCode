class Solution:
  def minOperations(self, nums: List[int]) -> int:
    return sum(bin(num).count('1') for num in nums) + len(bin(max(nums))) - 3
