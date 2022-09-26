class TrieNode:
  def __init__(self):
    self.children: Dict[str, TrieNode] = defaultdict(TrieNode)
    self.isWord = False


class WordDictionary:
  def __init__(self):
    self.root = TrieNode()

  def addWord(self, word: str) -> None:
    node: TrieNode = self.root
    for c in word:
      if c not in node.children:
        node.children[c] = TrieNode()
      node = node.children[c]
    node.isWord = True

  def search(self, word: str) -> bool:
    return self._dfs(word, 0, self.root)

  def _dfs(self, word: str, s: int, node: TrieNode) -> bool:
    if s == len(word):
      return node.isWord
    if word[s] != '.':
      next: TrieNode = node.children[word[s]]
      return self._dfs(word, s + 1, next) if next else False

    for c in string.ascii_lowercase:
      if c in node.children and self._dfs(word, s + 1, node.children[c]):
        return True

    return False
