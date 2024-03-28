class Solution:
  def calculateTime(self, keyboard: str, word: str) -> int:
    letterToIndex = {c: i for i, c in enumerate(keyboard)}
    return letterToIndex[word[0]] + \
        sum(abs(letterToIndex[a] - letterToIndex[b])
            for a, b in itertools.pairwise(word))
