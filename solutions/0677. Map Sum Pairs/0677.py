class TrieNode:
  def __init__(self):
    self.children: Dict[str, TrieNode] = {}
    self.sum = 0


class MapSum:
  def __init__(self):
    self.root = TrieNode()
    self.keyToVal = {}

  def insert(self, key: str, val: int) -> None:
    diff = val - self.keyToVal.get(key, 0)
    node: TrieNode = self.root
    for c in key:
      node = node.children.setdefault(c, TrieNode())
      node.sum += diff
    self.keyToVal[key] = val

  def sum(self, prefix: str) -> int:
    node: TrieNode = self.root
    for c in prefix:
      if c not in node.children:
        return 0
      node = node.children[c]
    return node.sum
