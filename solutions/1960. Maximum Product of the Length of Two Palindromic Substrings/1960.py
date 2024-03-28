class Solution:
  def maxProduct(self, s: str) -> int:
    n = len(s)

    def manacher(s: str) -> List[int]:
      maxExtends = [0] * n
      l2r = [1] * n
      center = 0

      for i in range(n):
        r = center + maxExtends[center] - 1
        mirrorIndex = center - (i - center)
        extend = 1 if i > r else min(maxExtends[mirrorIndex], r - i + 1)
        while i - extend >= 0 and i + extend < n and s[i - extend] == s[i + extend]:
          l2r[i + extend] = 2 * extend + 1
          extend += 1
        maxExtends[i] = extend
        if i + maxExtends[i] >= r:
          center = i

      for i in range(1, n):
        l2r[i] = max(l2r[i], l2r[i - 1])

      return l2r

    # l[i] := the maximum length of palindromes in s[0..i)
    l = manacher(s)
    # r[i] := the maximum length of palindromes in s[i..n)
    r = manacher(s[::-1])[::-1]
    return max(l[i] * r[i + 1] for i in range(n - 1))
