class Solution:
  def sumOfMultiples(self, n: int) -> int:
    # Returns the sum of multiples of value in [1, n].
    def sumOfMultiples(value: int) -> int:
      lo = value
      hi = (n // value) * value
      count = (hi - lo) // value + 1
      return (lo + hi) * count // 2

    return sumOfMultiples(3) + sumOfMultiples(5) + sumOfMultiples(7) \
        - (sumOfMultiples(15) + sumOfMultiples(21) + sumOfMultiples(35)) \
        + sumOfMultiples(105)
