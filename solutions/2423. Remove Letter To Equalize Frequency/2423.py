class Solution:
  def equalFrequency(self, word: str) -> bool:
    count = collections.Counter(word)

    # Try to remove each letter, then check if the frequency of all the letters
    # in the `word` are equal.
    for c in word:
      count[c] -= 1
      if self._equalFreq(count):
        return True
      count[c] += 1

    return False

  def _equalFreq(self, count: Dict[int, int]) -> bool:
    theFreq = -1
    for freq in count.values():
      if freq == 0 or freq == theFreq:
        continue
      if theFreq == -1:
        theFreq = freq
      else:
        return False
    return True
