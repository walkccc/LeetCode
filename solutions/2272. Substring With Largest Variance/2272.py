class Solution:
  def largestVariance(self, s: str) -> int:
    # A := the w// higher freq
    # B := the w// lower freq
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
          # An interval should contain at least one b
          ans = max(ans, countA - countB)
        elif countB == 0 and canExtendPrevB:
          # Edge case: consider previous b
          ans = max(ans, countA - 1)

        # Reset if # Of b > # Of a
        if countB > countA:
          countA = 0
          countB = 0
          canExtendPrevB = True

      return ans

    return max(kadane(c1, c2)
               for c1 in string.ascii_lowercase
               for c2 in string.ascii_lowercase
               if c1 != c2)
