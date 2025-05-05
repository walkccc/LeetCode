class Solution:
  def interchangeableRectangles(self, rectangles: list[list[int]]) -> int:
    ratioCount = collections.Counter()

    def gcd(a: int, b: int) -> int:
      return a if b == 0 else gcd(b, a % b)

    for width, height in rectangles:
      d = gcd(width, height)
      ratioCount[(width // d, height // d)] += 1

    return sum(c * (c - 1) // 2 for c in ratioCount.values())
