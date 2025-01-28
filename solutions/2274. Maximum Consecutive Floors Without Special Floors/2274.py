class Solution:
  def maxConsecutive(self, bottom: int, top: int, special: list[int]) -> int:
    ans = 0

    special.sort()

    for a, b in zip(special, special[1:]):
      ans = max(ans, b - a - 1)

    return max(ans, special[0] - bottom, top - special[-1])
