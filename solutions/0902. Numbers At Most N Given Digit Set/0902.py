class Solution:
  def atMostNGivenDigitSet(self, D: List[str], N: int) -> int:
    ans = 0
    num = str(N)

    for i in range(1, len(num)):
      ans += len(D)**i

    for i, c in enumerate(num):
      dHasSameNum = False
      for digit in D:
        if digit < c:
          ans += len(D)**(len(num) - i - 1)
        elif digit == c:
          dHasSameNum = True
      if not dHasSameNum:
        return ans

    return ans + 1
