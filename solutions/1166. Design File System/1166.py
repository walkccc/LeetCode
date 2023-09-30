class TrieNode:
  def __init__(self, value: int = 0):
    self.children: Dict[str, TrieNode] = {}
    self.value = value


class FileSystem:
  def __init__(self):
    self.root = TrieNode()

  def createPath(self, path: str, value: int) -> bool:
    node: TrieNode = self.root
    subpaths = path.split('/')

    for i in range(1, len(subpaths) - 1):
      if subpaths[i] not in node.children:
        return False
      node = node.children[subpaths[i]]

    if subpaths[-1] in node.children:
      return False
    node.children[subpaths[-1]] = TrieNode(value)
    return True

  def get(self, path: str) -> int:
    node: TrieNode = self.root

    for subpath in path.split('/')[1:]:
      if subpath not in node.children:
        return -1
      node = node.children[subpath]

    return node.value
