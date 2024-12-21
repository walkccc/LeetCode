class Solution:
  def oddCells(self, m: int, n: int, indices: list[list[int]]) -> int:
    # rows[i] and cols[i] :=
    #   true (flipped even times) / false (flipped odd times)
    rows = [False] * m
    cols = [False] * n

    for r, c in indices:
      rows[r] ^= True
      cols[c] ^= True

    return sum(rows[i] ^ cols[j]
               for i in range(m)
               for j in range(n))
