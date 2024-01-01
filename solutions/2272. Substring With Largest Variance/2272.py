class Solution:
  def largestVariance(self, s: str) -> int:
    # a := the letter with the higher frequency
    # b := the letter with the lower frequency
    def kadane(a: str, b: str) -> int:
      ans = 0
      countA = 0
      countB = 0
      canExtendPrevB = False

      for c in s:
        if c != a and c != b:
          continue
        if c == a:
          countA += 1
        else:
          countB += 1
        if countB > 0:
          # An interval should contain at least one b.
          ans = max(ans, countA - countB)
        elif countB == 0 and canExtendPrevB:
          # edge case: consider the previous b.
          ans = max(ans, countA - 1)
        # Reset if the number of b > the number of a.
        if countB > countA:
          countA = 0
          countB = 0
          canExtendPrevB = True

      return ans

    return max(kadane(a, b)
               for a in string.ascii_lowercase
               for b in string.ascii_lowercase
               if a != b)
