class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        seen = set()

        for i in range(9):
            for j in range(9):
                c = board[i][j]
                if c == '.':
                    continue
                if c + ' in row ' + str(i) in seen or \
                        c + ' in col ' + str(j) in seen or \
                        c + ' in box ' + str(i // 3) + str(j // 3) in seen:
                    return False
                seen.add(c + ' in row ' + str(i))
                seen.add(c + ' in col ' + str(j))
                seen.add(c + ' in box ' + str(i // 3) + str(j // 3))

        return True
