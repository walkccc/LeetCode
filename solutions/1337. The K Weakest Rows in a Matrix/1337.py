class Solution:
  def kWeakestRows(self, mat: list[list[int]], k: int) -> list[int]:
    rowSums = [(sum(row), i) for i, row in enumerate(mat)]
    return [i for _, i in sorted(rowSums)[:k]]
