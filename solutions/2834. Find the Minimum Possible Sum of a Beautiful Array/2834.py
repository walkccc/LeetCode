class Solution:
  # Same as 2829. Determine the Minimum Sum of a k-avoiding Array
  def minimumPossibleSum(self, n: int, target: int) -> int:
    # These are the unique pairs that sum up to k (target):
    # (1, k - 1), (2, k - 2), ..., (ceil(k // 2), floor(k // 2)).
    # Our optimal strategy is to select 1, 2, ..., floor(k // 2), and then
    # choose k, k + 1, ... if necessary, as selecting any number in the range
    # [ceil(k // 2), k - 1] will result in a pair summing up to k.
    kMod = 1_000_000_007

    def trapezoid(a: int, b: int) -> int:
      """Returns sum(a..b)."""
      return (a + b) * (b - a + 1) // 2

    mid = target // 2  # floor(k // 2)
    if n <= mid:
      return trapezoid(1, n)
    return (trapezoid(1, mid) + trapezoid(target, target + (n - mid - 1))) % kMod
