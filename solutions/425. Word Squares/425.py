class TrieNode:
  def __init__(self):
    self.children: dict[str, TrieNode] = collections.defaultdict(TrieNode)
    self.startsWith: list[str] = []


class Trie:
  def __init__(self, words: list[str]):
    self.root = TrieNode()
    for word in words:
      self._insert(word)

  def findBy(self, prefix: str) -> list[str]:
    node = self.root
    for c in prefix:
      if c not in node.children:
        return []
      node = node.children[c]
    return node.startsWith

  def _insert(self, word: str) -> None:
    node = self.root
    for c in word:
      node = node.children.setdefault(c, TrieNode())
      node.startsWith.append(word)


class Solution:
  def wordSquares(self, words: list[str]) -> list[list[str]]:
    if not words:
      return []

    n = len(words[0])
    ans = []
    path = []
    trie = Trie(words)

    for word in words:
      path.append(word)
      self._dfs(trie, n, path, ans)
      path.pop()

    return ans

  def _dfs(self, trie: Trie, n: int, path: list[str], ans: list[list[str]]):
    if len(path) == n:
      ans.append(path.copy())
      return

    prefix = self._getPrefix(path)

    for s in trie.findBy(prefix):
      path.append(s)
      self.dfs(trie, n, path, ans)
      path.pop()

  def _getPrefix(self, path: list[str]) -> str:
    """
    e.g. path = ["wall",
                 "area"]
       prefix =  "le.."
    """
    prefix = []
    index = len(path)
    for s in path:
      prefix.append(s[index])
    return ''.join(prefix)
