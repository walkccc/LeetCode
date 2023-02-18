class Solution:
  def isValidSudoku(self, board: List[List[str]]) -> bool:
    seen = set()

    for i in range(9):
      for j in range(9):
        c = board[i][j]
        if c == '.':
          continue
        if c + '@row ' + str(i) in seen or \
           c + '@col ' + str(j) in seen or \
           c + '@box ' + str(i // 3) + str(j // 3) in seen:
          return False
        seen.add(c + '@row ' + str(i))
        seen.add(c + '@col ' + str(j))
        seen.add(c + '@box ' + str(i // 3) + str(j // 3))

    return True
