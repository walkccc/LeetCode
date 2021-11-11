class Solution:
  def fractionAddition(self, expression: str) -> str:
    ints = list(map(int, re.findall('[+-]?[0-9]+', expression)))
    A = 0
    B = 1

    for a, b in zip(ints[::2], ints[1::2]):
      A = A * b + a * B
      B *= b
      g = math.gcd(A, B)
      A //= g
      B //= g

    return str(A) + '/' + str(B)
