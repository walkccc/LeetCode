class Solution:
  def integerBreak(self, n: int) -> int:
    # If an optimal product contains a factor f >= 4, then we can replace it
    # with 2 and f - 2 without losing optimality. As 2(f - 2) = 2f - 4 >= f,
    # we never need a factor >= 4, meaning we only need factors 1, 2, and 3
    # (and 1 is wasteful).
    # Also, 3 * 3 is better than 2 * 2 * 2, so we never use 2 more than twice.
    if n == 2:  # 1 * 1
      return 1
    if n == 3:  # 1 * 2
      return 2

    ans = 1

    while n > 4:
      n -= 3
      ans *= 3
    ans *= n

    return ans
