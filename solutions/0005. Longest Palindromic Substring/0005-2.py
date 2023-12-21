class Solution:
  def longestPalindrome(self, s: str) -> str:
    # '@' and '$' signs serve as sentinels appended to each end to avoid bounds
    # checking.
    t = '#'.join('@' + s + '$')
    n = len(t)
    # t[i - maxExtends[i]..i) ==
    # t[i + 1..i + maxExtends[i]]
    maxExtends = [0] * n
    center = 0

    for i in range(1, n - 1):
      rightBoundary = center + maxExtends[center]
      mirrorIndex = center - (i - center)
      maxExtends[i] = rightBoundary > i and \
          min(rightBoundary - i, maxExtends[mirrorIndex])

      # Attempt to expand the palindrome centered at i.
      while t[i + 1 + maxExtends[i]] == t[i - 1 - maxExtends[i]]:
        maxExtends[i] += 1

      # If a palindrome centered at i expand past `rightBoundary`, adjust
      # center based on expanded palindrome.
      if i + maxExtends[i] > rightBoundary:
        center = i

    # Find the `maxExtend` and `bestCenter`.
    maxExtend, bestCenter = max((extend, i)
                                for i, extend in enumerate(maxExtends))
    return s[(bestCenter - maxExtend) // 2:(bestCenter + maxExtend) // 2]
