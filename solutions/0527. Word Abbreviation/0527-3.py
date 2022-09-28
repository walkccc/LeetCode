class IndexedWord:
  def __init__(self, word: str, index: int):
    self.word = word
    self.index = index


class TrieNode:
  def __init__(self):
    self.children: Dict[str, TrieNode] = defaultdict(TrieNode)
    self.count = 0


class Solution:
  def wordsAbbreviation(self, words: List[str]) -> List[str]:
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

    abbrevToIndexedWords = defaultdict(list)

    for i, word in enumerate(words):
      abbrev = getAbbrev(word, 0)
      abbrevToIndexedWords[abbrev].append(IndexedWord(word, i))

    def insertWord(root: Optional[TrieNode], word: str) -> None:
      node = root
      for c in word:
        if not node.children[c]:
          node.children[c] = TrieNode()
        node = node.children[c]
        node.count += 1

    def firstUniqueIndex(root: Optional[TrieNode], word: str) -> None:
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
