class Solution:
  def minimumOperations(self, num: str) -> int:
    n = len(num)
    seenFive = False
    seenZero = False

    for i in range(n - 1, -1, -1):
      if seenZero and num[i] == '0':  # '00'
        return n - i - 2
      if seenZero and num[i] == '5':  # '50'
        return n - i - 2
      if seenFive and num[i] == '2':  # '25'
        return n - i - 2
      if seenFive and num[i] == '7':  # '75'
        return n - i - 2
      seenZero = seenZero or num[i] == '0'
      seenFive = seenFive or num[i] == '5'

    return n - 1 if seenZero else n
