class Solution:
  def findPattern(
      self,
      board: list[list[int]],
      pattern: list[str],
  ) -> list[int]:
    def isMatch(x: int, y: int) -> bool:
      digitToLetter = {}
      letterToDigit = {}
      for i, row in enumerate(pattern):
        for j, c in enumerate(row):
          digit = board[i + x][j + y]
          if c.isdigit():
            if int(c) != digit:
              return False
          else:
            if digitToLetter.get(digit, c) != c:
              return False
            if letterToDigit.get(c, digit) != digit:
              return False
            digitToLetter[digit] = c
            letterToDigit[c] = digit
      return True

    for x in range(len(board) - len(pattern) + 1):
      for y in range(len(board[0]) - len(pattern[0]) + 1):
        if isMatch(x, y):
          return [x, y]

    return [-1, -1]
