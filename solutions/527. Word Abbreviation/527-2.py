from dataclasses import dataclass


@dataclass
class IndexedWord:
  word: str
  index: int


class Solution:
  def wordsAbbreviation(self, words: list[str]) -> list[str]:
    n = len(words)
    ans = [''] * n

    def getAbbrev(s: str, prefixIndex: int) -> str:
      n = len(s)
      num = n - (prefixIndex + 1) - 1
      numLength = 1 if num < 10 else (2 if num < 100 else 3)
      abbrevLength = (prefixIndex + 1) + numLength + 1
      if abbrevLength >= n:
        return s
      return s[:prefixIndex + 1] + str(num) + s[-1]

    abbrevToIndexedWords = collections.defaultdict(list)

    for i, word in enumerate(words):
      abbrev = getAbbrev(word, 0)
      abbrevToIndexedWords[abbrev].append(IndexedWord(word, i))

    def longestCommonPrefix(s1: str, s2: str) -> int:
      i = 0
      while i < len(s1) and i < len(s2) and s1[i] == s2[i]:
        i += 1
      return i

    for indexedWords in abbrevToIndexedWords.values():
      indexedWords.sort(key=lambda x: x.word)
      lcp = [0] * len(indexedWords)
      for i, (a, b) in enumerate(zip(indexedWords, indexedWords[1:])):
        k = longestCommonPrefix(a.word, b.word)
        lcp[i] = max(lcp[i], k)
        lcp[i + 1] = k
      for iw, l in zip(indexedWords, lcp):
        ans[iw.index] = getAbbrev(iw.word, l)

    return ans
