class TrieNode:
  def __init__(self):
    self.children: Dict[str, TrieNode] = {}
    self.count = 0


class Trie:
  def __init__(self):
    self.root = TrieNode()

  def insert(self, word: str) -> None:
    node: TrieNode = self.root
    for c in word:
      node = node.children.setdefault(c, TrieNode())
      node.count += 1

  def search(self, word: str) -> bool:
    node: TrieNode = self.root
    for c in word:
      if c not in node.children:
        return False
      node = node.children[c]
    return node.count > 1


class Solution:
  def stringMatching(self, words: List[str]) -> List[str]:
    trie = Trie()

    for word in words:
      for i in range(len(word)):
        trie.insert(word[i:])

    return [word for word in words if trie.search(word)]
