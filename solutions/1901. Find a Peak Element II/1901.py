class Solution:
  def findPeakGrid(self, mat: list[list[int]]) -> list[int]:
    l = 0
    r = len(mat) - 1

    while l < r:
      m = (l + r) // 2
      if max(mat[m]) >= max(mat[m + 1]):
        r = m
      else:
        l = m + 1

    return [l, mat[l].index(max(mat[l]))]
