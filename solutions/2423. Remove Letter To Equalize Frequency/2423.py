class Solution:
  def equalFrequency(self, word: str) -> bool:
    count = collections.Counter(word)

    # Try to remove each letter, then check if the frequency of all letters in
    # word are equal
    for c in word:
      count[c] -= 1
      if self._equalCount(count):
        return True
      count[c] += 1

    return False

  def _equalCount(self, count: Dict[int, int]) -> bool:
    freq = -1
    for c in count.values():
      if c == 0 or c == freq:
        continue
      if freq == -1:
        freq = c
      else:
        return False
    return True
