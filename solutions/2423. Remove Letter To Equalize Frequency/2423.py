class Solution:
  def equalFrequency(self, word: str) -> bool:
    count = collections.Counter(word)

    # Try to remove each letter, then check if the frequency of all the letters
    # in `word` are equal.
    for c in word:
      count[c] -= 1
      if count[c] == 0:
        del count[c]
      if min(count.values()) == max(count.values()):
        return True
      count[c] += 1

    return False
