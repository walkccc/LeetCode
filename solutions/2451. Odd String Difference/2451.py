class Solution:
  def oddString(self, words: list[str]) -> str:
    def getDiff(s: str) -> list[int]:
      return [ord(b) - ord(a) for a, b in zip(s, s[1:])]

    wordAndDiffTuples = [(word, tuple(getDiff(word))) for word in words]
    diffTupleCount = collections.Counter()

    for _, diffTuple in wordAndDiffTuples:
      diffTupleCount[diffTuple] += 1

    for word, diffTuple in wordAndDiffTuples:
      if diffTupleCount[diffTuple] == 1:
        return word
