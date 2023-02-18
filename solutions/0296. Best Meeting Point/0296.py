class Solution:
  def minTotalDistance(self, grid: List[List[int]]) -> int:
    m = len(grid)
    n = len(grid[0])
    # I indices s.t. grid[i][j] == 1
    I = [i for i in range(m) for j in range(n) if grid[i][j]]
    # J indices s.t. grid[i][j] == 1
    J = [j for j in range(n) for i in range(m) if grid[i][j]]

    def minTotalDistance(grid: List[int]) -> int:
      summ = 0
      i = 0
      j = len(grid) - 1

      while i < j:
        summ += grid[j] - grid[i]
        i += 1
        j -= 1

      return summ

    # Sum(i - median(I)) + sum(j - median(J))
    return minTotalDistance(I) + minTotalDistance(J)
