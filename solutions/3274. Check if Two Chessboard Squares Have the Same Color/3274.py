class Solution:
  def checkTwoChessboards(self, coordinate1: str, coordinate2: str) -> bool:
    # Same as 1812. Determine Color of a Chessboard Square
    def squareIsWhite(coordinate: str) -> bool:
      letter, digit = coordinate
      return ord(letter) % 2 != int(digit) % 2

    return squareIsWhite(coordinate1) == squareIsWhite(coordinate2)
