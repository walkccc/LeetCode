class Solution:
  def checkInclusion(self, s1: str, s2: str) -> bool:
    count = collections.Counter(s1)
    required = len(s1)

    for r, c in enumerate(s2):
      count[c] -= 1
      if count[c] >= 0:
        required -= 1
      if r >= len(s1):  # The window is oversized.
        count[s2[r - len(s1)]] += 1
        if count[s2[r - len(s1)]] > 0:
          required += 1
      if required == 0:
        return True

    return False
