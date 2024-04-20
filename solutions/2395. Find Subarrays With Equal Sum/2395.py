class Solution:
  def findSubarrays(self, nums: List[int]) -> bool:
    seen = set()

    for a, b in zip(nums, nums[1:]):
      summ = a + b
      if summ in seen:
        return True
      seen.add(summ)

    return False
