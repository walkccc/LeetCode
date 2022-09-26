class Solution:
  def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
    prefix = 0
    mini = 0  # start from 0
    maxi = 0  # start from 0

    for d in differences:
      prefix += d
      mini = min(mini, prefix)
      maxi = max(maxi, prefix)

    return max(0, (upper - lower) - (maxi - mini) + 1)
