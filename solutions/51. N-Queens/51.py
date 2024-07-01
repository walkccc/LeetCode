class Solution:
  def solveNQueens(self, n: int) -> List[List[str]]:
    ans = []
    cols = [False] * n
    diag1 = [False] * (2 * n - 1)
    diag2 = [False] * (2 * n - 1)

    def dfs(i: int, board: List[int]) -> None:
      if i == n:
        ans.append(board)
        return

      for j in range(n):
        if cols[j] or diag1[i + j] or diag2[j - i + n - 1]:
          continue
        cols[j] = diag1[i + j] = diag2[j - i + n - 1] = True
        dfs(i + 1, board + ['.' * j + 'Q' + '.' * (n - j - 1)])
        cols[j] = diag1[i + j] = diag2[j - i + n - 1] = False

    dfs(0, [])
    return ans
