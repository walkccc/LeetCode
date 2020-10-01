class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        def isValid(row: int, col: int, c: str) -> bool:
            for i in range(9):
                if board[i][col] == c or \
                        board[row][i] == c or \
                        board[3 * (row // 3) + i // 3][3 * (col // 3) + i % 3] == c:
                    return False
            return True

        def dfs(s: int) -> bool:
            if s == 81:
                return True

            i = s // 9
            j = s % 9

            if board[i][j] != '.':
                return dfs(s + 1)

            for c in range(1, 10):
                if isValid(i, j, str(c)):
                    board[i][j] = str(c)
                    if dfs(s + 1):
                        return True
                    board[i][j] = '.'

            return False

        dfs(0)
