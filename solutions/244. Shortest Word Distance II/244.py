class WordDistance:
  def __init__(self, wordsDict: list[str]):
    self.wordToIndices = collections.defaultdict(list)
    for i, word in enumerate(wordsDict):
      self.wordToIndices[word].append(i)

  def shortest(self, word1: str, word2: str) -> int:
    indices1 = self.wordToIndices[word1]
    indices2 = self.wordToIndices[word2]
    ans = math.inf

    i = 0
    j = 0
    while i < len(indices1) and j < len(indices2):
      ans = min(ans, abs(indices1[i] - indices2[j]))
      if indices1[i] < indices2[j]:
        i += 1
      else:
        j += 1

    return ans
