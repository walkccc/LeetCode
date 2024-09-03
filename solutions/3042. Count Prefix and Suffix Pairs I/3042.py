class TrieNode:
  def __init__(self):
    self.children: dict[tuple[str, str], TrieNode] = {}
    self.count = 0


class Trie:
  def __init__(self):
    self.root = TrieNode()

  def insert(self, word: str) -> int:
    node = self.root
    count = 0
    for i, prefix in enumerate(word):
      suffix = word[-i - 1]
      node = node.children.setdefault((prefix, suffix), TrieNode())
      count += node.count
    node.count += 1
    return count


class Solution:
  def countPrefixSuffixPairs(self, words: list[str]) -> int:
    trie = Trie()
    return sum(trie.insert(word) for word in words)
