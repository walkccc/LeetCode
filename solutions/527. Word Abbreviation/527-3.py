from dataclasses import dataclass


@dataclass
class IndexedWord:
  word: str
  index: int


class TrieNode:
  def __init__(self):
    self.children: dict[str, TrieNode] = collections.defaultdict(TrieNode)
    self.count = 0


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

    def insertWord(root: TrieNode | None, word: str) -> None:
      node = root
      for c in word:
        node = node.children.setdefault(c, TrieNode())
        node.count += 1

    def firstUniqueIndex(root: TrieNode | None, word: str) -> None:
      node = root
      for i, c in enumerate(word):
        node = node.children[c]
        if node.count == 1:
          return i
      return len(word)

    for indexedWords in abbrevToIndexedWords.values():
      root = TrieNode()
      for iw in indexedWords:
        insertWord(root, iw.word)
      for iw in indexedWords:
        index = firstUniqueIndex(root, iw.word)
        ans[iw.index] = getAbbrev(iw.word, index)

    return ans
