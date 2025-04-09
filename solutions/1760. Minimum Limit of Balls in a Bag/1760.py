class Solution:
  def minimumSize(self, nums: list[int], maxOperations: int) -> int:
    def numOperations(m: int) -> int:
      """Returns the number of operations required to make m penalty."""
      return sum((num - 1) // m for num in nums)
    l = 1
    r = max(nums)
    return bisect.bisect_left(
        range(l, r),
        True, key=lambda m: numOperations(m) <= maxOperations) + l
