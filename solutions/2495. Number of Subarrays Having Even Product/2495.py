class Solution:
  def evenProduct(self, nums: list[int]) -> int:
    ans = 0
    numsBeforeEven = 0  # inclusively

    # e.g. nums = [1, 0, 1, 1, 0].
    # After meeting the first 0, set `numsBeforeEven` to 2. So, the number
    # between index 1 to index 3 (the one before next 0) will contribute 2 to
    # `ans`.
    for i, num in enumerate(nums):
      if num % 2 == 0:
        numsBeforeEven = i + 1
      ans += numsBeforeEven

    return ans
