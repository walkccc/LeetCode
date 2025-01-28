class Solution:
  def countCompleteSubstrings(self, word: str, k: int) -> int:
    uniqueLetters = len(set(word))
    return sum(self._countCompleteStrings(word, k, windowSize)
               for windowSize in range(k, k * uniqueLetters + 1, k))

  def _countCompleteStrings(self, word: str, k: int, windowSize: int) -> int:
    """
    Returns the number of complete substrings of `windowSize` of `word`.
    """
    res = 0
    countLetters = 0  # the number of letters in the running substring
    count = collections.Counter()

    for i, c in enumerate(word):
      count[c] += 1
      countLetters += 1
      if i > 0 and abs(ord(c) - ord(word[i - 1])) > 2:
        count = collections.Counter()
        # Start a new substring starting at word[i].
        count[c] += 1
        countLetters = 1
      if countLetters == windowSize + 1:
        count[word[i - windowSize]] -= 1
        countLetters -= 1
      if countLetters == windowSize:
        res += all(freq == 0 or freq == k for freq in count.values())

    return res
