class Solution:
  def checkIfCanBreak(self, s1: str, s2: str) -> bool:
    count1 = collections.Counter(s1)
    count2 = collections.Counter(s2)

    def canBreak(count1: dict[str, int], count2: dict[str, int]) -> bool:
      """Returns True if count1 can break count2."""
      diff = 0
      for c in string.ascii_lowercase:
        diff += count2[c] - count1[c]
        # count2 is alphabetically greater than count1.
        if diff < 0:
          return False
      return True

    return canBreak(count1, count2) or canBreak(count2, count1)
