class Solution:
  def atMostNGivenDigitSet(self, digits: list[str], n: int) -> int:
    ans = 0
    num = str(n)

    for i in range(1, len(num)):
      ans += pow(len(digits), i)

    for i, c in enumerate(num):
      dHasSameNum = False
      for digit in digits:
        if digit[0] < c:
          ans += pow(len(digits), len(num) - i - 1)
        elif digit[0] == c:
          dHasSameNum = True
      if not dHasSameNum:
        return ans

    return ans + 1
