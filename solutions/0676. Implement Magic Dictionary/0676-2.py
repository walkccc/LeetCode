class TrieNode:
  def __init__(self):
    self.children: Dict[str, TrieNode] = defaultdict(TrieNode)
    self.isWord = False


class MagicDictionary:
  def __init__(self):
    self.root = TrieNode()

  def buildDict(self, dictionary: List[str]) -> None:
    for word in dictionary:
      self._insert(word)

  def search(self, searchWord: str) -> bool:
    node: TrieNode = self.root
    for i, c in enumerate(searchWord):
      for letter in string.ascii_lowercase:
        if letter == c:
          continue
        child = node.children[letter]
        if not child:
          continue
        # replace searchWord[i] with `letter`,
        # then check if searchWord[i + 1:] match `child`
        if self._find(child, searchWord, i + 1):
          return True
      if not node.children[c]:
        return False
      node = node.children[c]
    return False

  def _insert(self, word: str) -> None:
    node: TrieNode = self.root
    for c in word:
      if c not in node.children:
        node.children[c] = TrieNode()
      node = node.children[c]
    node.isWord = True

  def _find(self, node: TrieNode, word: str, i: int) -> bool:
    for c in word[i:]:
      if c not in node.children:
        return False
      node = node.children[c]
    return node.isWord
