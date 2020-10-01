class Solution:
    def solve(self, board: List[List[str]]) -> None:
        def dfs(i: int, j: int) -> None:
            if not 0 <= i < len(board) or not 0 <= j < len(board[0]) or board[i][j] != 'O':
                return

            board[i][j] = '.'
            dfs(i + 1, j)
            dfs(i - 1, j)
            dfs(i, j + 1)
            dfs(i, j - 1)

        if not board:
            return

        for i in range(len(board)):
            dfs(i, 0)
            dfs(i, len(board[0]) - 1)

        for j in range(1, len(board[0]) - 1):
            dfs(0, j)
            dfs(len(board) - 1, j)

        for row in board:
            for i, c in enumerate(row):
                row[i] = 'O' if c == '.' else 'X'
