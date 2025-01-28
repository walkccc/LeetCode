# Definition for an infinite stream.
# class InfiniteStream:
#   def next(self) -> int:
#     pass

class Solution:
  # Same as 3023. Find Pattern in Infinite Stream I
  def findPattern(
      self,
      stream: Optional['InfiniteStream'],
      pattern: list[int]
  ) -> int:
    lps = self._getLPS(pattern)
    i = 0  # stream's index
    j = 0  # pattern's index
    bit = 0  # the bit in the stream
    readNext = False
    while True:
      if not readNext:
        bit = stream.next()
        readNext = True
      if bit == pattern[j]:
        i += 1
        readNext = False
        j += 1
        if j == len(pattern):
          return i - j
      # Mismatch after j matches.
      elif j > 0:
        # Don't match lps[0..lps[j - 1]] since they will match anyway.
        j = lps[j - 1]
      else:
        i += 1
        readNext = False

  def _getLPS(self, pattern: list[int]) -> list[int]:
    """
    Returns the lps array, where lps[i] is the length of the longest prefix of
    pattern[0..i] which is also a suffix of this substring.
    """
    lps = [0] * len(pattern)
    j = 0
    for i in range(1, len(pattern)):
      while j > 0 and pattern[j] != pattern[i]:
        j = lps[j - 1]
      if pattern[i] == pattern[j]:
        j += 1
        lps[i] = j
    return lps
