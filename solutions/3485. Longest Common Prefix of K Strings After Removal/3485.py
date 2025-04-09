class TrieNode:
  def __init__(self):
    self.children: dict[str, TrieNode] = {}
    self.count = 0


class Trie:
  def __init__(self, k: int):
    self.k = k
    self.root = TrieNode()
    self.prefixLengthsCount = collections.Counter()
    self.prefixLengths = SortedList()

  def insert(self, word: str) -> None:
    node = self.root
    for i, c in enumerate(word):
      sz = i + 1
      node = node.children.setdefault(c, TrieNode())
      node.count += 1
      if node.count >= self.k:
        self.prefixLengthsCount[sz] += 1
        if self.prefixLengthsCount[sz] == 1:
          self.prefixLengths.add(-sz)

  def erase(self, word: str) -> None:
    node = self.root
    for i, c in enumerate(word):
      sz = i + 1
      node = node.children[c]
      if node.count == self.k:
        self.prefixLengthsCount[sz] -= 1
        if self.prefixLengthsCount[sz] == 0:
          self.prefixLengths.remove(-sz)
      node.count -= 1

  def getLongestCommonPrefix(self) -> int:
    return 0 if not self.prefixLengths else -self.prefixLengths[0]


class Solution:
  def longestCommonPrefix(self, words: list[str], k: int) -> list[int]:
    ans = []
    trie = Trie(k)

    for word in words:
      trie.insert(word)

    for word in words:
      trie.erase(word)
      ans.append(trie.getLongestCommonPrefix())
      trie.insert(word)

    return ans
