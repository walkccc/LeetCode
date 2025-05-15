class Solution:
  def numberOfArrays(
      self,
      differences: list[int],
      lower: int,
      upper: int,
  ) -> int:
    prefix = 0
    mn = 0  # Starts from 0.
    mx = 0  # Starts from 0.

    for d in differences:
      prefix += d
      mn = min(mn, prefix)
      mx = max(mx, prefix)

    return max(0, (upper - lower) - (mx - mn) + 1)
