class TrieNode:
  def __init__(self):
    self.children: Dict[str, TrieNode] = {}


class Trie:
  def __init__(self):
    self.root = TrieNode()

  def insert(self, word: str) -> None:
    node: TrieNode = self.root
    for c in word:
      node = node.children.setdefault(c, TrieNode())

  def search(self, word: str) -> bool:
    node: TrieNode = self.root
    for c in word:
      if c not in node.children:
        return False
      node = node.children[c]
    return True


class Solution:
  def stringMatching(self, words: List[str]) -> List[str]:
    ans = []
    trie = Trie()

    for word in sorted(words, key=lambda x: -len(x)):
      if trie.search(word):
        ans.append(word)
      for i in range(len(word)):
        trie.insert(word[i:])

    return ans
