class Solution:
  def maxSelectedElements(self, nums: list[int]) -> int:
    ans = 1
    prev = -math.inf
    # the length of the longest consecutive elements (seq0) ending in the
    # previous number
    dp0 = 1
    # the length of the longest consecutive elements (seq1) ending in the
    # previous number + 1
    dp1 = 1

    for num in sorted(nums):
      if num == prev:
        dp1 = dp0 + 1  # Append `num + 1` to seq0.
      elif num == prev + 1:
        dp0 += 1  # Append `num` to seq0.
        dp1 += 1  # Add 1 to every number in seq0 and append `num + 1` to seq0.
      elif num == prev + 2:
        dp0 = dp1 + 1  # Append `num` to seq1.
        dp1 = 1        # Start a new sequence [`num + 1`].
      else:
        dp0 = 1  # Start a new sequence [`num`].
        dp1 = 1  # Start a new sequence [`num + 1`].
      ans = max(ans, dp0, dp1)
      prev = num

    return ans
