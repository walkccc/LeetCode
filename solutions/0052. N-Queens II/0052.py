class Solution:
    def totalNQueens(self, n: int) -> int:
        self.ans = 0

        self.dfs(0, [False] * n, [False] * (2 * n - 1), [False] * (2 * n - 1))

        return self.ans

    def dfs(self, y: int, cols: List[bool], diag1: List[bool], diag2: List[bool]) -> None:
        if y == len(cols):
            self.ans += 1
            return

        for x in range(len(cols)):
            if not cols[x] and not diag1[x + y] and not diag2[x - y + len(cols) - 1]:
                cols[x] = diag1[x + y] = diag2[x - y + len(cols) - 1] = True
                self.dfs(y + 1, cols, diag1, diag2)
                cols[x] = diag1[x + y] = diag2[x - y + len(cols) - 1] = False
