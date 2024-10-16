class Solution:
  def maxProduct(self, s: str) -> int:
    n = len(s)

    def manacher(s: str) -> list[int]:
      maxExtends = [0] * n
      leftToRight = [1] * n
      center = 0

      for i in range(n):
        r = center + maxExtends[center] - 1
        mirrorIndex = center - (i - center)
        extend = 1 if i > r else min(maxExtends[mirrorIndex], r - i + 1)
        while i - extend >= 0 and i + extend < n and s[i - extend] == s[i + extend]:
          leftToRight[i + extend] = 2 * extend + 1
          extend += 1
        maxExtends[i] = extend
        if i + maxExtends[i] >= r:
          center = i

      for i in range(1, n):
        leftToRight[i] = max(leftToRight[i], leftToRight[i - 1])

      return leftToRight

    # maxLeft[i] := the maximum odd length of palindromes in s[0..i]
    maxLeft = manacher(s)
    # maxRight[i] := the maximum odd length of palindromes in s[i..n - 1]
    maxRight = manacher(s[::-1])[::-1]
    return max(maxLeft[i - 1] * maxRight[i] for i in range(1, n))
