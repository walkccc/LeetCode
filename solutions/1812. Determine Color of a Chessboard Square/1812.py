class Solution:
  def squareIsWhite(self, coordinates: str) -> bool:
    letter, digit = coordinates
    return ord(letter) % 2 != int(digit) % 2
