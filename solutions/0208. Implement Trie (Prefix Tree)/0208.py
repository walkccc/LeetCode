class TrieNode:
  def __init__(self):
    self.children: Dict[str, TrieNode] = {}
    self.isWord = False


class Trie:
  def __init__(self):
    self.root = TrieNode()

  def insert(self, word: str) -> None:
    node: TrieNode = self.root
    for c in word:
      node = node.children.setdefault(c, TrieNode())
    node.isWord = True

  def search(self, word: str) -> bool:
    node: TrieNode = self._find(word)
    return node and node.isWord

  def startsWith(self, prefix: str) -> bool:
    return self._find(prefix)

  def _find(self, prefix: str) -> Optional[TrieNode]:
    node: TrieNode = self.root
    for c in prefix:
      if c not in node.children:
        return None
      node = node.children[c]
    return node
