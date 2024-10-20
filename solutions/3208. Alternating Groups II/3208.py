class Solution:
  def numberOfAlternatingGroups(self, colors: list[int], k: int) -> int:
    n = len(colors)
    ans = 0
    alternating = 1

    for i in range(n + k - 2):
      alternating = (1 if colors[i % n] == colors[(i - 1) % n]
                     else alternating + 1)
      if alternating >= k:
        ans += 1

    return ans
