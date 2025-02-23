class TrieNode:
  def __init__(self):
    self.children: dict[str, TrieNode] = collections.defaultdict(TrieNode)
    self.isWord = False


class Encrypter:
  def __init__(self, keys: list[str], values: list[str], dictionary: list[str]):
    self.keyToValue = {k: v for k, v in zip(keys, values)}
    self.valueToKeys = collections.defaultdict(list)
    self.root = TrieNode()
    for k, v in zip(keys, values):
      self.valueToKeys[v].append(k)
    for word in dictionary:
      self._insert(word)

  def encrypt(self, word1: str) -> str:
    return ''.join(self.keyToValue[c] for c in word1)

  def decrypt(self, word2: str) -> int:
    return self._find(word2, 0, self.root)

  def _insert(self, word: str) -> None:
    node = self.root
    for c in word:
      node = node.children.setdefault(c, TrieNode())
    node.isWord = True

  def _find(self, word: str, i: int, node: TrieNode) -> int:
    value = word[i:i + 2]
    if value not in self.valueToKeys:
      return 0

    ans = 0
    if i + 2 == len(word):
      for key in self.valueToKeys[value]:
        ans += node.children[key].isWord
      return ans

    for key in self.valueToKeys[value]:
      if key not in node.children:
        continue
      ans += self._find(word, i + 2, node.children[key])

    return ans
