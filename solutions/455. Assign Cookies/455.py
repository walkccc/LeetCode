class Solution:
  def findContentChildren(self, g: list[int], s: list[int]) -> int:
    g.sort()
    s.sort()

    i = 0
    for cookie in s:
      if i < len(g) and g[i] <= cookie:
        i += 1

    return i
