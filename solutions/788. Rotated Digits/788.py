class Solution:
  def rotatedDigits(self, n: int) -> int:
    def isGoodNumber(i: int) -> bool:
      isRotated = False

      for c in str(i):
        if c == '0' or c == '1' or c == '8':
          continue
        if c == '2' or c == '5' or c == '6' or c == '9':
          isRotated = True
        else:
          return False

      return isRotated

    return sum(isGoodNumber(i) for i in range(1, n + 1))
