class Solution:
  def findProductsOfElements(self, queries: list[list[int]]) -> list[int]:
    def sumBitsTill(x: int) -> int:
      """Returns sum(i.bit_count()), where 1 <= i <= x."""
      sumBits = 0
      powerOfTwo = 1
      while powerOfTwo <= x:
        sumBits += (x // (2 * powerOfTwo)) * powerOfTwo
        sumBits += max(0, x % (2 * powerOfTwo) + 1 - powerOfTwo)
        powerOfTwo *= 2
      return sumBits

    def sumPowersTill(x: int) -> int:
      """Returns sum(all powers of i), where 1 <= i <= x."""
      sumPowers = 0
      powerOfTwo = 1
      for power in range(x.bit_length()):
        sumPowers += (x // (2 * powerOfTwo)) * powerOfTwo * power
        sumPowers += max(0, x % (2 * powerOfTwo) + 1 - powerOfTwo) * power
        powerOfTwo *= 2
      return sumPowers

    def sumPowersFirstKBigNums(k: int) -> int:
      """Returns the sum of powers of the first k numbers in `big_nums`."""
      # Find the first number in [1, k] that has sumBitsTill(num) >= k.
      num = bisect.bisect_left(range(k), k, key=sumBitsTill)
      sumPowers = sumPowersTill(num - 1)
      remainingCount = k - sumBitsTill(num - 1)
      for power in range(num.bit_length()):
        if num >> power & 1:
          sumPowers += power
          remainingCount -= 1
          if remainingCount == 0:
            break
      return sumPowers

    return [pow(2,
                sumPowersFirstKBigNums(b + 1) -
                sumPowersFirstKBigNums(a), mod)
            for a, b, mod in queries]
