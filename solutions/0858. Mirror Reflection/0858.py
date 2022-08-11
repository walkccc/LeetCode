class Solution:
  def mirrorReflection(self, p: int, q: int) -> int:
    m = 1  # of room extension + 1
    n = 1  # of reflection + 1

    while m * p != n * q:
      n += 1
      m = n * q // p

    if m % 2 == 0 and n % 2 == 1:
      return 0
    if m % 2 == 1 and n % 2 == 1:
      return 1
    if m % 2 == 1 and n % 2 == 0:
      return 2
