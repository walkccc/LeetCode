class Solution:
  def maximumTotalSum(self, maximumHeight: list[int]) -> int:
    ans = 0
    mn = math.inf

    for height in sorted(maximumHeight, reverse=True):
      assigned = min(height, mn - 1)
      if assigned == 0:
        return -1
      ans += assigned
      mn = assigned

    return ans
