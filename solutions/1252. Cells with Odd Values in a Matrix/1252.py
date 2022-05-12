class Solution:
  def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
    ans = 0
    rows = [0] * n
    cols = [0] * m

    for indice in indices:
      rows[indice[0]] ^= 1
      cols[indice[1]] ^= 1

    for i in range(n):
      for j in range(m):
        ans += rows[i] ^ cols[j]

    return ans
