class Solution:
  def makeSimilar(self, nums: List[int], target: List[int]) -> int:
    nums.sort(key=lambda x: (x % 2, x))
    target.sort(key=lambda x: (x % 2, x))
    return sum(abs(a - b) for a, b in zip(nums, target)) // 4
