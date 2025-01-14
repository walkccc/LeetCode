class Solution:
  def kWeakestRows(self, mat: list[list[int]], k: int) -> list[int]:
    rowSums = [(sum(row), i) for i, row in enumerate(mat)]
    rowSums.sort(key=lambda x: (x[0], x[1]))
    return [i for _, i in rowSums[:k]]
