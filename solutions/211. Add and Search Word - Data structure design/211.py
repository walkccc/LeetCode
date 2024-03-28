class TrieNode:
  def __init__(self):
    self.children: Dict[str, TrieNode] = {}
    self.isWord = False


class WordDictionary:
  def __init__(self):
    self.root = TrieNode()

  def addWord(self, word: str) -> None:
    node: TrieNode = self.root
    for c in word:
      node = node.children.setdefault(c, TrieNode())
    node.isWord = True

  def search(self, word: str) -> bool:
    return self._dfs(word, 0, self.root)

  def _dfs(self, word: str, s: int, node: TrieNode) -> bool:
    if s == len(word):
      return node.isWord
    if word[s] != '.':
      child: TrieNode = node.children.get(word[s], None)
      return self._dfs(word, s + 1, child) if child else False
    return any(self._dfs(word, s + 1, child) for child in node.children.values())
