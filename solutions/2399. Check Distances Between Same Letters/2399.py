class Solution:
  def checkDistances(self, s: str, distance: List[int]) -> bool:
    firstSeenIndex = [-1] * 26

    for i, c in enumerate(s):
      j = ord(c) - ord('a')
      prevIndex = firstSeenIndex[j]
      if prevIndex != -1 and i - prevIndex - 1 != distance[j]:
        return False
      firstSeenIndex[j] = i

    return True
