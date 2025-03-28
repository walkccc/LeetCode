class Solution:
  def minimumOperations(self, nums: list[int]) -> int:
    seen = set()
    for i, num in reversed(list(enumerate(nums))):
      if num in seen:
        return (i + 1 + 2) // 3  # ceil((i + 1) / 3)
      seen.add(num)
    return 0
