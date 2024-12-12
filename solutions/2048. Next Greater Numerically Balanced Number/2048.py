class Solution:
  def nextBeautifulNumber(self, n: int) -> int:
    def isBalance(num: int) -> bool:
      count = [0] * 10
      while num > 0:
        if num % 10 == 0:
          return False
        count[num % 10] += 1
        num //= 10
      return all(c == i for i, c in enumerate(count) if c)

    n += 1
    while not isBalance(n):
      n += 1
    return n
