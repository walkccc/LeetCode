class Solution:
  def minOperations(self, nums: List[int], k: int) -> int:
    seen = set()

    for i, num in enumerate(reversed(nums)):
      if num > k:
        continue
      seen.add(num)
      if len(seen) == k:
        return i + 1
