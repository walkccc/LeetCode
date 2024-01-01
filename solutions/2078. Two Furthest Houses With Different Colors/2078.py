class Solution:
  def maxDistance(self, colors: List[int]) -> int:
    # The maximum distance always includes either the first or the last house.
    n = len(colors)
    i = 0  # the leftmost index, where colors[i] != colors[-1]
    j = n - 1  # the rightmost index, where colors[j] != colors[0]
    while colors[i] == colors[-1]:
      i += 1
    while colors[j] == colors[0]:
      j -= 1
    return max(n - 1 - i, j)
