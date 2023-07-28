class Solution:
  def minSwaps(self, s: str) -> int:
    ones = s.count('1')
    zeros = len(s) - ones
    if abs(ones - zeros) > 1:
      return -1

    def countSwaps(curr: str) -> int:
      swaps = 0
      for c in s:
        if c != curr:
          swaps += 1
        curr = chr(ord(curr) ^ 1)
      return swaps // 2

    if ones > zeros:
      return countSwaps('1')
    if zeros > ones:
      return countSwaps('0')
    return min(countSwaps('1'), countSwaps('0'))
