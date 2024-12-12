class Solution:
  def complexNumberMultiply(self, a: str, b: str) -> str:
    def getRealAndImag(s: str) -> tuple:
      return int(s[:s.index('+')]), int(s[s.index('+') + 1:-1])

    A, B = getRealAndImag(a)
    C, D = getRealAndImag(b)

    return str(A * C - B * D) + '+' + str(A * D + B * C) + 'i'
