class Solution:
  def evenProduct(self, nums: List[int]) -> int:
    ans = 0
    numsBeforeEven = 0  # Inclusively.

    # E.g., nums = [1, 0, 1, 1, 0].
    # After we meet the first 0, we set `numsBeforeEven` to 2. Therefore, the
    # num between index 1 to index 3 (the one before next 0) will contribute 2
    # to the ans.
    for i, num in enumerate(nums):
      if num % 2 == 0:
        numsBeforeEven = i + 1
      ans += numsBeforeEven

    return ans
